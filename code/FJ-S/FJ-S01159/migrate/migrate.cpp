#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e6+5;
int c,t,n,pos,x,y,z,now;
int r[N],dis[N],cnt[N];
bool vis[N];
ll d,ans;
ll a[N];
queue<int> que;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		pos=1;
		for(int i=1;i<=n;i++) {
			while(pos<=n) {
				if(a[pos]-a[i]>d) break;
				pos++;
			}
			r[i]=pos-1;
		}
		for(int i=1;i<=n;i++) {
			memset(dis,0x3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			while(!que.empty()) que.pop();
			que.push(i);
			dis[i]=0;
			cnt[i]=1;
			for(int i=1;i<=n;i++) f[i]=false;
			while(!que.empty()) {
				x=que.front();
				que.pop();
				if(f[x]) continue;
				f[x]=true;
				for(int j=x+1;j<=r[x];j++) {
					if(dis[x]+1<dis[j]) {
						dis[j]=dis[x]+1;
						cnt[j]=cnt[x];
						que.push(j);
					}
					else if(dis[x]+1==dis[j])
						cnt[j]+=cnt[x];
				}
			}
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
// O(t*n*(n+m))
// 相信相信的力量吧
// 希望能 1= 呀
