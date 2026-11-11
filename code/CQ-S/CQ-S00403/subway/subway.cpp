#include<bits/stdc++.h>
using namespace std;

#define sht short
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define xwy114514 ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll INTINF=0x7f7f7f7f;
const ll LONGINF=0x3f3f3f3f3f3f3f3f;

const ll MMax=5e5+10;
const ll NMax=500+10;
const ll DMax=20+10;
const ll QMax=1e5+10;

ll c,m,n,d,q;
vector<pair<ll,ll> >is_in[MMax];//这个点在那些线路里面 
ll w[MMax];//这个点到地铁口的时间
vector<pair<ll,ll> >e[MMax+NMax];//带权双向边 
ll Min[NMax][NMax];
ll dis[NMax][NMax],vis[NMax];

void add_pair_e(ll u,ll v,ll w){e[u].push_back({v,w}),e[v].push_back({u,w});}

void solve(ll S){
	for(ll i=1;i<=n;i++)dis[S][i]=LONGINF,vis[i]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
	pq.push({0,S});dis[S][S]=0;
	while(pq.size()){
		ll u=pq.top().second;pq.pop();
		if(vis[u])continue;vis[u]=1;
		for(ll i=0;i<e[u].size();i++){
			ll v=e[u][i].first,w=e[u][i].second;
			if(dis[S][v]>dis[S][u]+w){
				dis[S][v]=dis[S][u]+w;
				pq.push({dis[S][v],v});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	xwy114514;
	
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,u,w,k;i<=n;i++){cin>>k;while(k--)cin>>u>>w,is_in[u].push_back({i,w});}
	for(ll i=1;i<=n;i++)for(ll j=i+1;j<=n;j++)Min[i][j]=Min[j][i]=LONGINF;
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<is_in[i].size();j++){
			for(ll k=j+1;k<is_in[i].size();k++){
				ll u=is_in[i][j].first,uw=is_in[i][j].second;
				ll v=is_in[i][k].first,vw=is_in[i][k].second;
				Min[u][v]=min(Min[u][v],uw+vw);
				Min[v][u]=min(Min[v][u],uw+vw);
			}
		}
	}
	for(ll i=1;i<=n;i++)for(ll j=i+1;j<=n;j++)if(Min[i][j]!=LONGINF)add_pair_e(i,j,Min[i][j]);
	for(ll i=1;i<=n;i++)solve(i);
	for(ll i=1,u,v;i<=q;i++){
		cin>>u>>v;
		ll ans=LONGINF;
		for(ll j=0;j<is_in[u].size();j++){
			for(ll k=0;k<is_in[v].size();k++){
				ll a=is_in[u][j].first,aw=is_in[u][j].second;
				ll b=is_in[v][k].first,bw=is_in[v][k].second;
				ans=min(ans,dis[a][b]+aw+bw);
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	
	return 0;
}
/*
我们发现每次走相当于是从包含其地铁线路的虚电出发，因为其中边权为0所以不影响
那么我们处理地铁线路到地铁线路之间的最小距离，再加上两个地铁站出战的权值
能行吗？想一下 就是这样的哈哈哈 
 
那都不用拆点了啊 这太简单了 

我们又发现直接做复杂度好像超了50倍
能优化吗

反正一定是处理两个线路之间的最短路，然后要考虑一下怎么快速求解，普通的不行
瓶颈在于点数所以我们先处理两个线路间的最短距离
怎么处理 因为两个线路肯定是由一个点连接起来的，所以对于这两个线路建一条新的边权值为两者之和
然后对于建边只需要枚举每个点，然后枚举点连接的站点，然后处理一下最小值方便后面建新边
O(m*d*d) 还是超时？啥意思 不对不对 肯定跑不满，因为最多覆盖5e5个点，
那么满打满算拥有20个点的数量不超过5e5/20 那么再乘个20*20应该是不会超时的吧嘿嘿 
这里就算O(m*d+n*n*log(n^2)+q*d*d)=O(1e7+2.5e5+4e7) 

那我再看看呢，，，后面那个真的能优化掉吗
前面都卡满了，后面不能再卡了
其实只是少了8分吧，，，算了先想一下，想到25就写 后面大暴力 

少个pp 我少打了个0.。。算出来才5e7我直接切掉好吧 
*/
