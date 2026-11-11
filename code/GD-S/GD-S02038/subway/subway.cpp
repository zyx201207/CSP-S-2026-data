#include<bits/stdc++.h>
#define longlong long long
//#define longlong __int128_t
#define ll (longlong)
namespace NOTLE{
	void NOTLE(){
		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
	void NO_TLE(){
//		std::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
}
using namespace std;
bool frein=false,freout=false,refrein=false;
const longlong int_max=0x3f3f3f3f3f3f3f3fll;
struct Edge{
	longlong end,kind,off;
	Edge(){
		end=0ll,kind=0ll,off=0ll;
		return;
	}
	Edge(longlong END,longlong KIND,longlong OFF){
		end=END,kind=KIND,off=OFF;
		return;
	}
};
struct NOW{
	longlong now,kind,dis;
	NOW(){
		now=0ll,kind=0ll,dis=int_max;
		return;
	}
	NOW(longlong now,longlong KIND,longlong DIS){
		now=now,kind=KIND,dis=DIS;
		return;
	}
	friend bool operator < (NOW a,NOW b){
		if(a.dis==b.dis){
			if(a.now==b.now)	return a.kind<b.kind;
			return a.now<b.now;
		}
		return a.dis<b.dis;
	}
	friend bool operator > (NOW a,NOW b){
		if(a.dis==b.dis){
			if(a.now==b.now)	return a.kind>b.kind;
			return a.now>b.now;
		}
		return a.dis>b.dis;
	}
	friend bool operator <= (NOW a,NOW b){return not(a>b);}
	friend bool operator >= (NOW a,NOW b){return not(a<b);}
	friend bool operator == (NOW a,NOW b){return ((a.dis==b.dis) and (a.now==b.now) and (a.kind==b.kind));}
	friend bool operator != (NOW a,NOW b){return not(a==b);}
};
vector < Edge > edges[500010ll];
longlong c,n,m,d,q,w[500010ll],k[510ll];
longlong Do_It_Just(longlong start,longlong end){
	vector < longlong > dises(m+10ll,int_max);
	vector < bool > cans(m+10ll,true);
	priority_queue < NOW > que;
	que.push(NOW(-start,-0ll,-0ll));
	dises[start]=0ll;
	while(not(que.empty())){
		longlong now=-que.top().now,kind=-que.top().kind,dis=-que.top().dis;
		que.pop();
		if(not(cans[now]))	continue;
		if(dises[now]<dis)	continue;
		cans[now]=false;
	}
	return dises[end]+w[start]+w[end];
}
signed main(){
	NOTLE::NO_TLE();
	freopen("subway.in","r",stdin),frein=true;
	freopen("subway.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(refrein)	printf("%lld %lld %lld %lld %lld\n",c,n,m,d,q);
	for(longlong i=1ll;i<=m;i++){
		scanf("%lld",&w[i]);
		if(refrein)	printf("%lld ",w[i]);
	}
	for(longlong i=1ll;i<=n;i++){
		scanf("%lld",&k[i]);
		if(refrein)	printf("%lld ",k[i]);
		longlong x=0ll,y=0ll,p=0ll,q=0ll;
		for(longlong j=0ll;j<=k[i];j++){
			x=y,p=q;
			scanf("%lld%lld",&y,&q);
			if(refrein)	printf("%lld %lld ",y,q);
			if(x==0ll)	continue;
			edges[x].push_back(Edge(y,i,q));
			edges[y].push_back(Edge(x,i,p));
		}
	}
	while(q--){
		longlong x,y;
		scanf("%lld%lld",&x,&y);
		if(refrein)	printf("%lld %lld\n",x,y);
		if(x==y){
			printf("0\n");
			continue;
		}
		printf("%lld\n",Do_It_Just(x,y));
	}
	return 0;
}
