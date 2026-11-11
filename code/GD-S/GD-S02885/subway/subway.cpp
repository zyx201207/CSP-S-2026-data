#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=5e5+5;
constexpr int M=505;
int c,n,m,d,q,k[M];
ll w[N];
map<int,map<int,ll> >a;
map<int,map<int,int> >v;
inline ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-1LL;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10LL+(c-'0');
		c=getchar();
	}
	return x*y;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main(){
//	freopen("subway4.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			v[i][j]=read(); a[i][j]=read();
			a[j][i]=a[i][j];
		}
	}
	while(q--){
		int st=0,en=0;
		st=read(); en=read();
		priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
		pq.push({0,st});
		vector<ll>dis(m+5,0x3f3f3f3f3f3f3f3f);
		while(!pq.empty()){
			ll ti=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(dis[u]<=ti) continue;
			dis[u]=ti;
			for(int i=1;i<=n;i++){
				int id=-1;
				for(int j=1;j<=k[i];j++){
					if(v[i][j]==u){
						id=j;
						break;
					}
				}
				if(id==-1) continue;
				ll sum=w[u]+dis[u]+a[i][id];
				for(int j=1;j<=k[i];j++){
					int nxt=v[i][j];
					if(nxt==u) continue;
					if(sum>=dis[nxt]) continue;
					if(nxt!=en) pq.push({sum,nxt});
					dis[nxt]=sum;
				}
			}
		}
		write(dis[en]);
		printf("\n");
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
