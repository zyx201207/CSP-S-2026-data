#include<bits/stdc++.h>
typedef long long ll;
const bool islocal=0;
std::ifstream fin("subway.in");
std::ofstream fout("subway.out");
ll c,n,m,d,q,w[500005],dis[500505];
std::bitset<500505>vis;
std::vector<std::vector<std::pair<ll,ll>>>vec(500505);
void Dijkstra(ll st,ll en){
	std::multiset<std::pair<ll,ll>>q;
	memset(dis,0x3f,sizeof dis),dis[st]=0,vis.reset(),q.insert({0,st});
	while(q.size()){
		std::pair<ll,ll>p=*q.begin();
		q.erase(q.begin());
		if(vis[p.second])continue;
		vis[p.second]=1;
		if(p.second==en)return;
		for(std::pair<ll,ll>v:vec[p.second])if(dis[v.second]>p.first+v.first)dis[v.second]=p.first+v.first,q.insert({dis[v.second],v.second});
	}
}
int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	(islocal?std::cin:fin)>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)(islocal?std::cin:fin)>>w[i];
	for(ll i=1,k;i<=n;i++){
		(islocal?std::cin:fin)>>k;
		for(ll j=0,a,t;j<k;j++){
			(islocal?std::cin:fin)>>a>>t;
			vec[i].push_back({t,a+n}),vec[a+n].push_back({t,i}); 
		}
	}
	for(ll i=0,s,t;i<q;i++)(islocal?std::cin:fin)>>s>>t,Dijkstra(s+n,t+n),(islocal?std::cout:fout)<<dis[t+n]+w[s]+w[t]<<'\n';
}
//我没有使用f r e o p e n，这是真的，兑。 
