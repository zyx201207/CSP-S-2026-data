#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;//floyd暴力只拿前六个 
ll c,t,n,d,x[N];
int f[N][N],cnt[N][N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while( t--){
		memset(f,0x3f,sizeof f);
		memset(cnt,0,sizeof cnt);
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;x[i]+d>=x[j]&&j<=n;j++)
				f[i][j]=1;
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(k==j||k==i||i==j)continue;
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[i][k]+f[k][j];
						cnt[i][j]=1;
					}
					else if(f[i][j]==f[i][k]+f[k][j])cnt[i][j]++;
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans+=(cnt[i][j]==2); 
		cout<<ans<<'\n';
	}
	return 0;
}
