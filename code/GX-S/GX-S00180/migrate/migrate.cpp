#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll a[505][505],vis[505][505];
ll z[505];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==1||c==2||c==3||c==4||c==5||c==6){
		while(t--){
			int n,d;
			cin>>n>>d;
			//int pre[505];
			//pre[0]=0;
			for(int i=1;i<=n;++i){
				scanf("%lld",&z[i]);
			}
			for(int i=1;i<=n;++i){
				for(int j=1;j<i;++j){
					a[i][j]=a[j][i]=2147483647;
					if(z[i]-z[j]<=d) a[i][j]=1;
				}
			}
			for(int k=1;k<=n;++k){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=i;++j){
						if(a[i][j]>a[i][k]+a[k][j]){
							vis[i][j]=1;
							a[i][j]=a[i][k]+a[k][j];
						}
						else if(a[i][j]==a[i][k]+a[k][j]){
								vis[i][j]++;
						}
					}
				}
			}
			ll cnt=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(vis[i][j]-1==2){
						++cnt;
					}
					cout<<vis[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<cnt<<endl;
		}
		
	}
	return 0;
}
