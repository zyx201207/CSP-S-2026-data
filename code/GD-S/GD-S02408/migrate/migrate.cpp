#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,m;
int d[401][401];
int a[401];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				d[i][j]=5e18;
			}
		}
		fill(a+1,a+n+1,0);
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(abs(a[i]-a[j])<=m){
					d[i][j]=d[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(i==j||d[i][k]==5e18||d[k][j]==5e18)continue;
					if(d[i][k]+d[k][j]<d[i][j]){
						d[i][j]=d[i][k]+d[k][j];
					}
				}
			}
		}
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=n;++j){
//				cout<<d[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		int ans=0,flag,cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				flag=min(d[i][j],d[j][i]);
				if(flag==5e18)continue;
				cnt=0;
				for(int k=1;k<=n;++k){
					if(d[i][k]+d[k][j]==flag||d[j][k]+d[k][i]==flag){
						cnt++;
					}
				}
				ans+=(cnt==2);
			}
		}
		cout<<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
