#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define eb emplace_back
#define fir first
#define sec second
using namespace std;
const int BUFSIZE=1<<20;
char ibuf[BUFSIZE],*Is=ibuf,*It=ibuf;
inline char gc(){if(Is==It)It=(Is=ibuf)+fread(ibuf,1,BUFSIZE,stdin);return Is==It?EOF:*Is++;}
inline ll read(){
	ll x=0;int f=1;char c=gc();
	while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=gc();
	return x*f;
}
void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
const int N=2e6+5,INF=2e9;
int c,T,n,dis[N],cnt[N];
ll d,a[N],ans;
vector<int>ve[N];
priority_queue<pii,vector<pii>,greater<pii>>q;
inline void dijkstra(int s){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)dis[i]=INF;
	q.push(mkp(0,s)),dis[s]=0;
	while(!q.empty()){
		int u=q.top().sec,w=q.top().fir;q.pop();
		if(dis[u]<w)continue;
		for(int v:ve[u]){
			if(dis[u]+1<dis[v])dis[v]=dis[u]+1,q.push(mkp(dis[v],v)),cnt[v]=1;
			else if(dis[u]+1==dis[v])cnt[v]++;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		if(n>5000){puts("0");continue;}
		for(int i=1;i<=n;i++)ve[i].clear();
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
				else ve[i].eb(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cnt[j]=0;
			dijkstra(i);
			for(int j=1;j<=n;j++)ans+=(cnt[j]==2);
		}
		write(ans),puts("");
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
