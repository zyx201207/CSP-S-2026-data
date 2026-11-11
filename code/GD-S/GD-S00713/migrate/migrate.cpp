#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,mf[N],X[N];
int vis[N];
int dis[N];
bool vis2[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios;
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>X[i];
		}
		for(int i=1;i<=n;i++){
			int l=i+1,r=n;
			mf[i]=i;
			while(l<=r){
				int mid=l+r>>1;
				if(X[mid]-X[i]<=d){
					mf[i]=mid;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
		}
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					vis[j]=0;
					dis[j]=inf;
				}
				dis[i]=0;
				for(int j=i-1;j>=1;j--){
					if(mf[j]>=i){
						dis[j]=1;
						continue;
					}
					if(dis[mf[j]]==inf)break;
					dis[j]=dis[mf[j]]+1;
					if(vis[mf[j]]==3){
						vis[j]=3;
						continue;
					}
					int l=j,r=mf[j],cnt=j;
					int res=dis[mf[j]];
					while(l<=r){
						int mid=l+r>>1;
						if(dis[mid]<=res){
							cnt=mid;
							r=mid-1;
						}else{
							l=mid+1;
						}
					}
					if(mf[j]-cnt+1>2){
						vis[j]=3;
						continue;
					}
					if(cnt==mf[j]){
						if(vis[mf[j]]==2){
							ans++;
							vis[j]=2;
						}
						continue;
					}
					if(!vis[cnt]&&!vis[mf[j]]){
						ans++;
						vis[j]=2;
					}else{
						vis[j]=3;
						continue;
					}
				}
			}
//			cout<<'\n';
			cout<<ans<<'\n';
			continue;
		}
		if(c==11||c==12){
			if(mf[1]==1||mf[1]==2){
				cout<<0<<'\n';
				continue;
			}
			int len=mf[1]-1,ans=0;
			int flag=0;
			for(int i=1;i<=n;i++)vis2[i]=0;
			for(int i=1;i<=n;i++){
				if(vis2[i])continue;
				int cnt=0;
				for(int j=i;j<=n;j+=len){
					vis2[j]=1;
					cnt++;
				}
				if(cnt>=3){
					flag=1;ans+=cnt-2;
				}
			}
			cout<<ans+flag<<'\n';
			continue;
		}
	}
	return 0;
}

