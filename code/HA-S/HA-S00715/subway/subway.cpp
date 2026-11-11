#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct lqp{
	long long v,t;
};
struct yzc{
	long long bh,jl;
	bool operator<(const yzc&xxx) const{
		return jl>xxx.jl;
	}
};
long long n,m,c,d,q,w[700001],dmin[1000][1000],dis[700001],dq,xr,yr,ans;
vector<lqp>a[700001];
const int M=510000;
long long xx;char cc;
int inline read(){
	xx=0;cc=getchar();
	while(!isdigit(cc))cc=getchar();
	while(isdigit(cc)){
		xx=(xx<<3)+(xx<<1)+(cc^48);
		cc=getchar();
	}
	return xx;
}
void dijst(int x){
	long long dqjl,dqbh;
	priority_queue<yzc>p;
	fill(dis,dis+700000,1LL*10000000*100000000);
	p.push({x,0});dis[x]=0;
	while(!p.empty()){
		dqjl=p.top().jl;
		dqbh=p.top().bh;
		p.pop();
		if(dqjl>dis[dqbh])continue;
		for(auto&s:a[dqbh]){
			if(dis[dqbh]+s.t<dis[s.v]){
				dis[s.v]=dis[dqbh]+s.t;
				p.push({s.v,dis[s.v]});
			}
		}
	}for(int i=1;i<=n;i++)dmin[x-M][i]=dis[i+M];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	long long k,aij,tij;
	for(int i=1;i<=n;i++){
		k=read();a[i+M].resize(k+1);
		for(int r=1;r<=k;r++){
			aij=read();tij=read();
			a[aij].push_back({i+M,tij});
			a[i+M].push_back({aij,tij});
		}
	}
	for(int i=1;i<=n;i++)dijst(i+M);
	while(q--){
		ans=1LL*100000000*100000000;
		xr=read();yr=read();
		for(auto&s:a[xr]){
			for(auto&ee:a[yr]){
				ans=min(ans,dmin[s.v-M][ee.v-M]+s.t+ee.t);
			}
		}cout<<ans+w[xr]+w[yr]<<"\n";
	}
	return 0;
}
