//15 at 17:17
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define fi first
#define se second 
#define popc(x) __builtin_popcount(x)
using ll=long long;
using ull=unsigned long long;
using ld=long double;
#define FILE "hub"
// #define FOR_ONLINE
// #define TEST_FOR_MS
// #define //freopen(x) //feropen(x)
bool mst;
const int N=1e6+5;
ll c,T;
int n,k,dis[N];
bool col[N],vis[N];
vector<int>e[N];
void dfs1(int now){
	vis[now]=1;
	for(auto it:e[now]){
		if(col[it]&&!vis[it])	dfs1(it);
	}
}
void dfs2(int now){
	for(auto it:e[now]){
		if(dis[it]>dis[now]+1)	dis[it]=dis[now]+1,dfs2(it);
	}
}
void solve_small(){
	int ans=0x3f3f3f3f;
	for(int i=1;i<(1<<n);i++){
		if(popc(i)==k){
			for(int j=0;j<n;j++)	col[j+1]=((i>>j)&1),vis[j+1]=0;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(col[j]&&!vis[j])	cnt++,dfs1(j);
			}
			// cerr<<i<<" "<<cnt<<"\n";
			if(cnt<=2){
				for(int j=1;j<=n;j++)	dis[j]=col[j]?0:0x3f3f3f3f;
				// for(int j=1;j<=n;j++)	cerr<<dis[j]<<" ";cerr<<"\n";
				for(int j=1;j<=n;j++)	dfs2(j);
				// for(int j=1;j<=n;j++)	cerr<<dis[j]<<" ";cerr<<"\n";
				int tmp=0;
				for(int j=1;j<=n;j++)	tmp=max(tmp,dis[j]);
				ans=min(ans,tmp);
			}
		}
	}
	cout<<ans<<"\n";
}
void Main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)	e[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(c<=3)	solve_small();
}
bool med;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef FOR_ONLINE
#ifndef TEST_FOR_MS
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
#else
	string x;cin>>x;
	freopen(("down/"FILE"/"FILE+x+".in").c_str(),"r",stdin);
	freopen(FILE".out","w",stdout);
#endif
#endif
	cerr<<fixed<<setprecision(6)<<abs(&med-&mst)/1024.0/1024<<"MB\n";
	double st=clock();
	cin>>c>>T;
	while(T--)  Main();
	cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
}
/*
WorldMachine suki

11.4 是我的生日，整理迷惑行为大赏的能祝我生日快乐吗

许愿世界机器可以天天开心啊

我去怎么 300 了，那再许个愿让我 AK -S 好不好

我去怎么 T4 倒闭了

为啥拿个 5pts 还这么费劲，人类呢。

事已至此大家还是都去听比例摩托的 Look At Me 吧
*/