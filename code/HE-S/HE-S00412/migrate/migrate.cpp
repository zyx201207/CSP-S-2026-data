#include<bits/stdc++.h>
using namespace std;
int c,t,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		int n,d;
		int di[n+5][n+5];
		int a[n+5];
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for (int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if (abs(a[i]-a[j])<=d){
					di[i][j]==abs(a[i]-a[j]);
				}
				else{
					di[i][j]==-1;
				}
			}
		}
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				for(int k=1;k<=n;++k){
					if(di[u][v]!=-1&&di[u][k]+di[k][v]>di[u][v]){
						di[u][v]=di[u][k]+di[k][v];
					}
				}
			}
		}
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				int s=0;
				for(int k=1;k<=n;++k){
					if(di[u][k]+di[k][v]==di[u][v]){
						s++;
					}
				}
				if(s==2){
					ans++;
				}
			}
		}
		cout<<ans/2;
	} 
}
