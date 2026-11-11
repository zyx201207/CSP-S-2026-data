#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
		(c=='-')?(f=-1):(f=f),c=getchar();
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}void write(ll x){
	if(x<0)
		putchar('-'),x=-x;
	if(x<10)
		putchar(x+'0');
	else
		write(x/10),putchar(x%10+'0');
	return;
}int c,t,n;
bool visd[N];
vector<int>g[N];
int cnt[N],dis[N];
vector<int>temp[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void solve(int st){
	while(!q.empty())
		q.pop();
	for(int i=1;i<=n;++i)
		dis[i]=N,visd[i]=false,cnt[i]=0;
	dis[st]=0;
	q.push(make_pair(dis[st],st));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(visd[u])
			continue;
		visd[u]=1;
		for(int v:g[u]){
			if(dis[v]==dis[u]+1)
				++cnt[v]; 
			else if(dis[v]>dis[u]+1)
				cnt[v]=1,dis[v]=dis[u]+1,q.push(make_pair(dis[v],v));
		}
	}return;
}ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ll ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;++i)
			x[i]=read();
		for(int i=1;i<n;++i){
			g[i].clear();
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]<=d)
					g[i].emplace_back(j);
				else
					break;
			}
		}for(int i=1;i<=n-1;++i){
			solve(i);
			for(int j=i+1;j<=n;++j){
				if(cnt[j]==2)
					++ans;
			}
		}write(ans),putchar('\n');
	}return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/

