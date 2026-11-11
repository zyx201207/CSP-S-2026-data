#include<bits/stdc++.h>
#define ll long long
#define NUM(x,y) (1ll*x*N+y)
#define BUF (1<<20)
char buf[BUF],*p1,*p2;
#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,BUF,stdin)),p1==p2)?EOF:*p1++)
void read_int(int &x){
	char ch=gc();x=0;
	int sig=1;
	while(ch<'0'||ch>'9'){if(ch=='-')sig=-1;ch=gc();}
	while(ch>='0'&&ch<='9')x=x*10+(ch^'0'),ch=gc();
	x*=sig;
}
void read(ll &x){
	char ch=gc();x=0;
	int sig=1;
	while(ch<'0'||ch>'9'){if(ch=='-')sig=-1;ch=gc();}
	while(ch>='0'&&ch<='9')x=x*10+(ch^'0'),ch=gc();
	x*=sig;
}
using namespace std;
const int N=2e6+5,TT=5e3+5;
int c,T,n,dis[TT],cnt[TT];
ll d,x[N],ans;
void bfs(int s){
	queue<pair<int,int>>q;
	q.push(make_pair(s,0)),dis[s]=0,cnt[s]=1;
	while(!q.empty()){
		pair<int,int>u=q.front();
		q.pop();
		for(int i=u.first+1;i<=n;++i){
			if(x[i]-x[u.first]>d)break;
			if(dis[i]>u.second+1)dis[i]=u.second+1,cnt[i]=cnt[u.first],q.push(make_pair(i,dis[i]));
			else if(dis[i]==u.second+1)cnt[i]=min(10,cnt[i]+cnt[u.first]);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read_int(c),read_int(T);
	while(T--){
		read_int(n),read(d),ans=0;
		for(int i=1;i<=n;++i)
			read(x[i]);
		for(int i=1;i<=n;++i){
			memset(dis,0x3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			bfs(i);
			for(int j=i+1;j<=n;++j)
				ans+=(cnt[j]==2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

