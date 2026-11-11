#include<bits/stdc++.h>
typedef long long ll;
const bool islocal=0;
std::ifstream fin("hub.in");
std::ofstream fout("hub.out");
ll c,t,n,k,a[1000005],dis[1000005];
std::bitset<1000005>vis;
std::vector<std::vector<ll>>vec(1000005);
std::set<ll>choice;
void rd_shuffle(ll seed){
	std::mt19937 rd(seed);
	for(ll i=0;i<n/2;i++)std::swap(a[rd()%n+1],a[rd()%n+1]);
}
void ext(ll s1,ll s2,ll seed){
	std::mt19937 rd(seed);
	std::queue<ll>q;
	choice.clear(),vis.reset(),q.push(s1),q.push(s2),choice.insert(s1),choice.insert(s2);
	while(q.size()){
		if(choice.size()==k)return;
		ll f=q.front();
		q.pop();
		if(vis[f])continue;
		vis[f]=1;
		for(ll v:vec[f])if(rd()%k<k-choice.size())q.push(v),choice.insert(v);
	}
}
ll ds(){
	std::queue<ll>q;
	memset(dis,0x3f,sizeof dis),vis.reset();
	for(ll x:choice)dis[x]=0,q.push(x);
	while(q.size()){
		ll f=q.front();
		q.pop();
		if(vis[f])continue;
		vis[f]=1;
		for(ll v:vec[f])if(dis[v]>dis[f]+1)dis[v]=dis[f]+1,q.push(v);
	}
	return*std::max_element(dis+1,dis+n+1);
}
int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	for(ll i=0;i<1000005;i++)a[i]=i;
	ll t0=clock(),limit;
	(islocal?std::cin:fin)>>c>>t,limit=3000/t-10;
	for(ll i=0;i<t;i++){
		(islocal?std::cin:fin)>>n>>k;
		for(ll i=1,u,v;i<n;i++)(islocal?std::cin:fin)>>u>>v,vec[u].push_back(v),vec[v].push_back(u);
		ll minn=LLONG_MAX,ut=0,st=clock();
		while(1){
			rd_shuffle(clock());
			if(n<100)ext(a[1],a[2],clock());
			else{choice.clear();for(ll i=1;i<=k;i++)choice.insert(a[i]);}
			minn=std::min(minn,ds());
			if(clock()-t0+ut>limit)break;
			if(!ut)ut=clock()-t0;
		}
		t0=clock(),(islocal?std::cout:fout)<<minn<<'\n';
		for(ll i=1;i<=n;i++)vec[i].clear();
	}
}
//freopen("hub.in","r",stdin),freopen("hub.out","w",stdout); 
