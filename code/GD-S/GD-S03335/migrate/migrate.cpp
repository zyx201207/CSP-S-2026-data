#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;

inline ll read(){
	char ch=getchar();ll xx=0,f=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return xx*f;
}

int c,T;
int n,dis[N],ans[N];
ll x[N],d,s;
vector<int> g[N];

void dijk(int bg){
	priority_queue<pair<int,int>> q;
	for(int i=1;i<=n;i++)
		dis[i]=1e8,ans[i]=0;
	dis[bg]=0;
	q.push({0,bg});
	while(!q.empty()){
		int l=-q.top().first;
		int u=q.top().second;
		q.pop();
		for(int v:g[u]){
			int dist=l+1;
			if(dist<dis[v]){
				dis[v]=dist;
				q.push({-dist,v});
				ans[v]=0;
			}
			if(dist==dis[v])
				ans[v]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(i!=bg && ans[i]==2)s++;
}

int main(){
	//
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			x[i]=read(),g[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ll dist=abs(x[i]-x[j]);
				if(dist>d || i==j)continue;
				g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
			dijk(i);
		cout<<(s/2)<<"\n";
		s=0;
	}
	return 0;
}
