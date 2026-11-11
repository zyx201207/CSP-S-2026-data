#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MAXN=5005;
int c,t,n,ans;
ll d,x[MAXN],f[MAXN][MAXN],cnt[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(f,0x3f,sizeof f);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			f[i][i]=0;
		}cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					f[i][j]=1;
				}
			}
		}for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ll newD=f[i][k]+f[k][j];
					if(newD<f[i][j]){
						f[i][j]=newD;
						cnt[i][j]=1;
					}else if(newD==f[i][j]){
						cnt[i][j]++;
					}
				}
			}
		}for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}cout<<ans<<'\n';
	}return 0;
}
