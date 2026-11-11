#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],t[505][N],a[N][25],cnt[N];
long long ans;
bool vis[N];
queue<int> que;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int num,time;
			cin>>num>>time;
			cnt[num]++;
			a[num][cnt[num]]=i;
			t[i][num]=time;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		memset(vis,0,sizeof(vis));
		ans=0;
		ans+=(w[u]+w[v]);
		que.push(u);
		vis[u]=true;
		while(!que.empty()){
			int x=que.front();
			if(x==v) break;
			for(int i=1;i<=cnt[x];i++){
				if(!vis[a[x][i]]){
					que.push(a[x][i]);
					vis[a[x][i]]=true;
				}
			}
			que.pop();
			ans+=t[1][x];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
