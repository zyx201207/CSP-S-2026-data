#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
long long a[maxn],g[maxn][maxn],x[maxn][maxn],cnt[maxn][maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=0;g[i][j]=1e18+7;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long k=abs(a[j]-a[i]);
				if(k<=d)g[i][j]=g[j][i]=1;
				x[i][j]=x[j][i]=k;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(g[i][k]+g[k][j]<g[i][j]&&x[i][k]+x[k][j]<=d){
						cnt[i][j]=0;
						g[i][j]=g[i][k]+g[k][j];
						x[i][j]=x[i][k]+x[k][j];
					}else if(g[i][k]+g[k][j]==g[i][j]){
						cnt[i][j]++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
