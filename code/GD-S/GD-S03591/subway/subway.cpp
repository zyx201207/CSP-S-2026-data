#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define ll long long 
char Begin;
using namespace std;
ll read(){
	ll num=0;
	char ch;ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58){
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}return num;
}
const int N=5e5+15;
const int M=505;
const ll inf=1e18;
int tid,n,m,K,Q;
struct node{int x;ll t;};
vector<node>a[N];
ll w[N],d[M][M];
char End;
int main(){
	cerr<<(&End-&Begin)/1024/1024<<endl;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	tid=read(),m=read(),n=read(),K=read(),Q=read();
	fr(i,1,n)w[i]=read();
	fr(i,1,m)fr(j,1,m)d[i][j]=inf;
	fr(i,1,m)d[i][i]=0;
	fr(i,1,m){
		int len=read();
		fr(j,1,len){
			int u=read();ll t=read();
			for(node p:a[u])d[i][p.x]=d[p.x][i]=min(d[p.x][i],p.t+t);
			a[u].push_back({i,t});
		}
	}
	fr(k,1,m)fr(i,1,m)fr(j,1,m)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(Q--){
		int u=read(),v=read();
		ll ans=inf;
		for(node i:a[u])for(node j:a[v])
			ans=min(ans,i.t+j.t+d[i.x][j.x]);
		printf("%lld\n",ans+w[u]+w[v]);
	}
}