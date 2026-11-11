#include<bits/stdc++.h>
#define siz(_) ((int)_.size())
#define pb emplace_back
#define mk make_pair
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=1e6+5;
int n,k;
vector<int> v[N];
int dep[N],s[N];
void dfs(int x,int fa){
	s[x]=x;
	int mx=0;
	for(auto u:v[x]){
		if(u==fa) continue;
		dep[u]=dep[x]+1;
		dfs(u,x);
		if(dep[s[u]]>mx){
			s[x]=s[u];
		}
	}
}
bool vis[N];
int K[N],cnt[N];
vector<int> q1,q2;
void bfs(int aa,int bb){
	for(int i=1;i<=n;i++) vis[i]=cnt[i]=0;
	q1.clear();
	q2.clear();
	q2.pb(aa);
	q2.pb(bb);
	K[aa]=K[bb]=0;
	for(int t=1;t<=n;t++){
	swap(q1,q2);
	while(!q1.empty()){
		int x=q1.back();q1.pop_back();
		if(vis[x]) continue;
		vis[x]=1;++cnt[K[x]];
		for(auto u:v[x]){
			if(vis[u]) continue;
			K[u]=K[x]+1;
			q2.push_back(u);
		}
	}
	}
	int res=0;
	for(int i=n;i>=1;i--){
		res+=cnt[i];
		if(res>=k) break;
	}
}
void Main(){
	n=read();k=read();
	for(int i=1;i<=n;i++) v[i].clear();
	int x,y;
	for(int i=2;i<=n;i++){
		x=read();y=read();
		v[x].pb(y);v[y].pb(x);
	}
	if(k==1){
		dfs(1,0);
		int r=s[1];
		dep[r]=0;
		dfs(r,0);
		printf("%d\n",(dep[s[r]]+1)/2);
		return;
	}
	int ans=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bfs(i,j);
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int Cid=read(),T=read();
	while(T--) Main();
	return 0;
}
