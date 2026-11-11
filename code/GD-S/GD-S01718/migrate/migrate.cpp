#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,x[2000005],s[2000005],dis[2000005],ans,mn;
vector<ll>g[2000005];
ll read(){
	ll c=getchar(),f=1,x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void write(ll x){
	if(x==0)return;
	if(x<0){putchar('-');x=-x;}
	write(x/10);
	putchar(x%10+'0');
}
void bfs(ll x){
	memset(dis,0x3f,sizeof(dis));
	memset(s,0,sizeof(s));
	dis[x]=0;
	s[x]=1;
	queue<pair<ll,ll>>q;
	q.push({x,0});
	while(q.size()){
		ll x=q.front().first,y=q.front().second;
		q.pop();
		if(dis[x]!=y)continue;
		for(auto i:g[x]){
			if(dis[i]>dis[x]+1){
				dis[i]=dis[x]+1;
				s[i]=s[x];
				q.push({i,dis[i]});
			}
			else if(dis[i]==dis[x]+1)s[i]+=s[x];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	t=read();c=read();
	if(c==11||c==12){
		while(t--){
			n=read();d=read();
			for(int i=1;i<=n;i++){
				x[i]=read();
			}
			if(d<=x[2]-x[1]||d>=x[n]-x[1])putchar('0');
			else write(max(0LL,n-d/(x[2]-x[1])*2+1));
			putchar('\n');
		}
		return 0;
	}
	while(t--){
		mn=LLONG_MAX;
		n=read();d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
			if(i!=1)mn=min(mn,x[i]-x[i-1]);
		}
		if(d<mn){putchar('0');putchar('\n');continue;}
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)g[i].push_back(j);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				if(s[j]==2)ans++; 
			}
		}
		write(ans);putchar('\n');
	}
	return 0; 
}
