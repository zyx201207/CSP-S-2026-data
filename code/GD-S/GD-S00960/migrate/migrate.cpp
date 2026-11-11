#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=2e6+5,M=3e2+5;
const int INF=0x3f3f3f3f,MOD=1e9+7;
typedef long long LL;
int c,t,n,d,a[N],dis[M][M],cnt[M][M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c<=6){
			memset(dis,0,sizeof dis);
			memset(cnt,0,sizeof cnt);
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					int pos=i,cnt=0;
					while(pos<j){
						cnt = 0;
						while(pos+1<=j&&cnt+a[pos+1]-a[pos]<=d)cnt+=a[pos+1]-a[pos],pos++;
						dis[i][j]++;
						if(!cnt){
							dis[i][j] = INF*INF;
							break;
						}
					}
					cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
				}
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=i+1;k<j;k++)
						if(dis[i][k]+dis[k][j]==dis[i][j])
							cnt[i][j]++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(cnt[i][j]==2)
						ans++,cout<<i<<" "<<j<<endl;
			cout<<ans<<endl;
		} 
	}
	return 0;
}
/*
dis[i][k]+dis[k][j]=dis[i][j]
dis[i][j]-dis[k][j]=dis[i][k]
*/
