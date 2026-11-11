#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline int read(){
	char ch=getchar();int xx=0,f=1;
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

struct node{
	int to,val;
};

int c;
int n,m,d,q;
int w[500005],k[505];
ll dis[500510];
vector<node> g[500510];

ll dijk(int bg,int ed){
	priority_queue<pair<ll,int>> q;
	for(int i=1;i<=(n+m);i++)
		dis[i]=1e18;
	dis[bg]=0;
	q.push({0,bg});
	while(!q.empty()){
		ll l=-q.top().first;
		int u=q.top().second;
		q.pop();
		for(node it:g[u]){
			int v=it.to;
			int w=it.val;
			ll dist=1ll*w+l;
			if(dist<dis[v]){
				dis[v]=dist;
				q.push({-dist,v});
			}
		}
	}
	return (dis[ed]+1ll*w[ed]+1ll*w[bg]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		//idx->i+m
		for(int j=1;j<=k[i];j++){
			int u=read(),v=i+m,w=read();
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	//此时有n+m个点!
	while(q--){
		int s=read(),t=read();
		cout<<dijk(s,t)<<"\n";
	} 
	return 0;
}
