#include<iostream>
#include<queue>
#include<string.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int c,t,n,d,dis[maxn],cnt[maxn],a[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) dis[j]=1e18;
			memset(cnt,0,sizeof(cnt));
			dis[i]=0;
			cnt[i]=1;
			for(int j=i;j<=n;j++){
				if(cnt[j]==2) ans++;
				for(int p=j+1;p<=n&&a[p]-a[j]<=d;p++){
					if(dis[p]>dis[j]+1){
						dis[p]=dis[j]+1;
						cnt[p]=cnt[j];
					}
					else if(dis[p]==dis[j]+1){
						cnt[p]+=cnt[j];
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
			
