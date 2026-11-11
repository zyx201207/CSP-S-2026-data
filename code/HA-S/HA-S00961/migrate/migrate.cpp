#include<bits/stdc++.h>
using namespace std;

int c,t;
int x[20005];
int g[20005][20005];
int m[20005][20005];
int main(){
	
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	int n,d,ans=0;
	
	while(t--){
		memset(g,0,sizeof(g));
		memset(m,0,sizeof(m));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<n;j++){
				if(x[j]-x[i]>d){
					break;
				}
				g[i][j]=x[j]-x[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int sum=j-i;
				for(int k=i+1;k<j;k++){
					if(!g[i][k]){
						sum--;
					}else if(!g[k][j]){
						sum--;
					}
				}
				if((sum==3&&!g[i][j])){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
	
}
