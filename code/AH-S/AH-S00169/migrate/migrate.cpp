#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int c,T,n,a[MAXN],dis[MAXN],cnt[MAXN];
bool vis[MAXN];
vector<int> e[MAXN];
void spfa(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	queue<int> q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	cnt[s]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		vis[s]=0;
		for(int i=0;i<e[t].size();i++){
			int to=e[t][i];
			if(dis[to]==dis[t]+1) cnt[to]+=cnt[t];
			else if(dis[to]>dis[t]+1){
				dis[to]=dis[t]+1;
				cnt[to]=cnt[t];
				if(!vis[to]){
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,d,ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d) e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			spfa(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
