#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int head[1000005];
int to[2000005];
int nxt[2000005],tot;
void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int bj[105];
int Bj[105];
void Dfs(int u){
	Bj[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(Bj[v]==1) continue;
		if(bj[v]==0) continue;
		Dfs(v);
	}
}
int checker(){
	int cnt=0;
	for(int i=1;i<=n;i++) Bj[i]=0;
	for(int i=1;i<=n;i++){
		if(bj[i]==1 && Bj[i]==0){
			Dfs(i);
			cnt++;
		}
	}
	if(cnt<=2) return 1;
	return 0;
}
int ANSS=0;
int DFS(int x,int fa,int d){
	if(bj[x]==1) return d;
	int ans=11;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		ans=min(ans,DFS(v,x,d+1));
	}
	return ans;
}
int cx(int u){
	return DFS(u,0,0);
}
void dfs(int now,int cnt){
	if(now==n+1){
		if(cnt<k) return;
		if(checker()==0){
			return;
		}
		int ANS=0;
		for(int i=1;i<=n;i++){
			if(bj[i]==0){
				ANS=max(ANS,cx(i));
			}
		}
		ANSS=min(ANSS,ANS); 
		return;
	}
	if(cnt<k) bj[now]=1,dfs(now+1,cnt+1);
	bj[now]=0;
	dfs(now+1,cnt);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) head[i]=0;tot=0;
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	if(n<=10){
		ANSS=11;
		dfs(1,0);
		cout<<ANSS<<'\n';
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
