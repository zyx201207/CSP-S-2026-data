//CCF I love you.Could you please give me more scores?
//中国计算机协会我爱您。您可否乐意给予我更多的得分呢？
using i128=__int128;
using u128=unsigned __int128;
const i128 INF=(static_cast<__int128>(1)<<126)+((static_cast<__int128>(1)<<126)-1);
const i128 NEG=-INF-1;
#include<cstdio>
#define MIAO(_x,_y) freopen(_x,"r",stdin);freopen(_y,"w",stdout);
template<typename T=__int128>
inline T read(){T t{};bool f=0;char c=getchar();
	while(c!=EOF&&(c<'0'||c>'9'))f=c=='-',c=getchar();
	while(c!=EOF&&!(c<'0'||c>'9'))t*=10,t+=c-'0',c=getchar();
	if(c!=EOF)ungetc(c,stdin);
	return f?-t:t;
}
template<typename T>
inline void write(const T&t){
	if(t<0)return putchar('-'),write(-t);
	if(t>9)write(t/10);
	putchar(t%10+'0');
}
#include<vector>
#include<queue>
i128 c,n,m,d,q,k,a,b;
std::vector<std::vector<std::pair<i128,i128>>>e;
std::vector<std::vector<i128>>dis;
std::vector<bool>v;
std::priority_queue<std::pair<i128,i128>,std::vector<std::pair<i128,i128>>,std::greater<std::pair<i128,i128>>>pq;
std::vector<i128>w;
inline void dijk(const i128&s){
	if(!dis[s].empty())return;
	v.assign(m+1,{});
	dis[s].assign(m+1,INF);
	dis[s][s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto x=pq.top().second;pq.pop();
		if(v[x])continue;
		v[x]=1;
		for(const auto&i:e[x]){
			auto y=i.first;auto wt=i.second;
			if(dis[s][y]>dis[s][x]+wt){
				dis[s][y]=dis[s][x]+wt;
				if(!v[y])pq.push({dis[s][y],y});
			}
		}
	}
}
int main(){
	MIAO("subway.in","subway.out");
	c=read();n=read();m=read();d=read();q=read();
	w.resize(m+1);e.resize(m+1);dis.resize(m+1);
	for(i128 i=1;i<=m;i++)w[i]=read();
	std::vector<std::pair<i128,i128>>tmp;
	for(i128 i=1;i<=n;i++){
		k=read();tmp.assign(k+1,{});
		for(i128 j=1;j<=k;j++){
			tmp[j].first=read();tmp[j].second=read();
			for(i128 l=1;l<j;l++){
				e[tmp[l].first].push_back({tmp[j].first,tmp[l].second+tmp[j].second});
				e[tmp[j].first].push_back({tmp[l].first,tmp[l].second+tmp[j].second});
			}
		}
	}
	while(q--){
		a=read();b=read();
		dijk(a);write(dis[a][b]+w[a]+w[b]);putchar('\n');
	}
	return 0;
}
/*
dijkstra?	-10/31 15:37
！？ $n\le500$ ？！	-10/31 15:40
大肘子给测试点编号。测试点竟然敢等分。这无疑是想让我们这种蒟蒻骗分的。赞美太阳！	-10/31 15:46
空悲切！	-10/31 15:54
只有部分分能够让我活得更加通透。	-10/31 16:05
预估分数50pts	-10/31 16:34
*/