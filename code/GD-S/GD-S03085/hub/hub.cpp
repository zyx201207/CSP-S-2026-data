#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int c,t,n,k,ans=1e9,len[N],v[N][N],vis[N],dis[N][N],vvis[N];
queue<int>q;
void bfs(int s){
	for (int i=1;i<=n;i++)vvis[i]=0;
	for (int i=1;i<=n;i++)dis[s][i]=1e9;
	q.push(s);
	vvis[s]=1;dis[s][s]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for (int i=1;i<=len[now];i++){
			int nxt=v[now][i];
			if (vvis[nxt])continue;
			vvis[nxt]=1;
			dis[s][nxt]=dis[s][now]+1;
			q.push(nxt);
		}
	}
}
void dfs1(int now){
	for (int i=1;i<=len[now];i++){
		int nxt=v[now][i];
		if (vvis[nxt])continue;
		if (!vis[nxt])continue;
		vvis[nxt]=1;
		dfs1(nxt);
	}
}
void dfs(int now,int sum){
	if (sum>k)return ;
	if (sum==k){
		int cnt=0;
		for (int i=1;i<=n;i++)vvis[i]=0;
		for (int i=1;i<=n;i++){
			if (vvis[i]==0&&vis[i]==1){
				cnt++;
				vvis[i]=1;
				dfs1(i);
			}
			if (cnt>2)return ;
		}
		int Ans=0;
		for (int i=1;i<=n;i++){
			if (vis[i])continue;
			int tmp=1e9;
			for (int j=1;j<=n;j++){
				if (!vis[j])continue;
				tmp=min(tmp,dis[i][j]);
			}
			Ans=max(tmp,Ans);
		}
		ans=min(ans,Ans);
		return ;
	}
	if (now>n)return ;
	vis[now]=1;
	dfs(now+1,sum+1);
	vis[now]=0;
	dfs(now+1,sum);
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c>>t;
	while(t--){
		ans=1e9;
		cin >>n>>k;
		for (int i=1;i<=n;i++)len[i]=0;
		for (int i=1;i<n;i++){
			int a,b;
			cin >>a>>b;
			len[a]++;
			len[b]++;
			v[a][len[a]]=b;
			v[b][len[b]]=a;
		}
		for (int i=1;i<=n;i++)bfs(i);
		dfs(1,0);
		cout <<ans<<"\n";
	}
	return 0;
}
