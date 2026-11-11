#include<iostream>
#include<queue>
#define ll long long
using namespace std;
const int N=2e6+5,INF=1e9;
int o,n;
int d[N],c[N];
ll m;
ll a[N];
bool v[N];

inline ll read(){
	ll x=0;
	int f=1;
	char c=getchar();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return f==-1?-x:x;
}

queue<int> q;

int bfs(int s){
	for(int i=1;i<=n;i++) d[i]=INF,c[i]=0,v[i]=0;
	while(q.size()) q.pop();
	d[s]=0,c[s]=1,q.push(s);
	while(q.size()){
		int x=q.front();
		q.pop();
		if(v[x]) continue;
		v[x]=1;
		for(int y=x+1;y<=n;y++){
			if(a[y]-a[x]>m) break;
			if(d[y]>d[x]+1){
				d[y]=d[x]+1,c[y]=c[x];
				q.push(y);
			}
			else if(d[y]==d[x]+1) c[y]=min(3,c[y]+c[x]);
		}
	}
	int res=0;
	for(int i=s+1;i<=n;i++){
		if(c[i]==2) res++;
	}
	return res;
}

void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(o>=13&&o<=14){
		int p;
		for(int i=1;i<=n;i++){
			if(a[n]-a[i]<=m){
				p=i;
				break;
			}
		}
		if(p<=2||p>=n-1){
			puts("0");
			return;
		}
		ll ans=0;
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[p+1]-a[i]<=m&&a[p+2]-a[i]>m) c++;
		}
		for(int i=p+1;i<=n;i++){
			if(a[i]-a[p-1]<=m&&a[i]-a[p-2]>m&&a[1]==a[p]-m) ans++;
			if(a[i]-a[p-1]>m) ans+=c; 
		}
		printf("%lld\n",ans);
		return;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=bfs(i);
	printf("%lld\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	o=read();
	int T=read();
	while(T--) solve();
	return 0;
}

