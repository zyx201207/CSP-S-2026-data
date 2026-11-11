#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define DF(i,a,b) for(int i=(a);i>=(b);i--)
#define pt array<int,2>
const int N=1e6+10;
int c,T,n,k,d[N],si[N],son[N],top[N],f[N],vis[N],mxd,rt1,rt2;
vector<int>g[N];
bool cmp(int x,int y){return d[x]<d[y];}
void dfs1(int u,int fa){
	d[u]=d[fa]+1;f[u]=fa;si[u]=1;
	if(d[u]>mxd)mxd=d[u],rt1=u;
	for(int v:g[u]){
		if(v==fa)continue;
		dfs1(v,u);si[u]+=si[v];
		if(!son[u]||si[son[u]]<si[v])son[u]=v;
	}
}
void dfs2(int u,int to){
	top[u]=to;
	if(!son[u])return;
	dfs2(son[u],to);
	for(int v:g[u])if(v!=f[u]&&v!=son[u])dfs2(v,v);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]])swap(x,y);
		x=f[top[x]];
	}
	return d[x]<d[y]?x:y;
}
int dis(int x,int y){
	return d[x]+d[y]-2*d[lca(x,y)];
}
void dfs3(int u,int fa){
	d[u]=d[fa]+1;
	if(d[u]>mxd)rt2=u,mxd=d[u];
	for(int v:g[u]){
		if(v==fa)continue;
		dfs3(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		F(i,1,n)g[i].clear(),d[i]=top[i]=son[i]=si[i]=f[i]=vis[i]=0;
		F(i,2,n){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,0);dfs2(1,1);
		if(n<=10){
			int all=(1ll<<n)-1,ans=1e18;
			F(msk,0,all){
				if(__builtin_popcount(msk)!=k)continue;
				vector<int>node;int cnt=1,tmp=msk;
				while(tmp){
					if(tmp&1)node.push_back(cnt);
					cnt++;tmp>>=1;
				}
				cnt=0;
				F(i,1,n)vis[i]=0;
				for(int x:node)vis[x]=1;
				for(int x:node)if(!vis[f[x]])cnt++;
				if(cnt>2)continue;
				tmp=0;
				F(i,1,n){
					if(!vis[i]){
						int res=1e18;
						for(int x:node)res=min(res,dis(x,i));
						tmp=max(tmp,res);
					}
				}
				ans=min(ans,tmp);
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c==13||c==14){
			int m=(n+1)/2;
			int dd=(k-2)/4,lp=(k-2)%4;
			int ans=0;
			if(m&1&&lp<2){
				m/=2;
				ans=max({ans,m-m/2-dd+1,m/2-dd+1});
			}else{
				m/=2;
				ans=max({ans,m-m/2-dd,m/2-dd});
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c==7||c==11||c==12){
			F(i,1,n)d[i]=0;
			mxd=0;
			dfs3(rt1,0);
//			cout<<rt1<<" "<<rt2<<"\n";
			int t1=rt1,t2=rt2;
			vector<int>way1,way2,way;
			while(t1!=1)way1.push_back(t1),t1=f[t1];
			while(t2!=1)way2.push_back(t2),t2=f[t2];
			reverse(begin(way2),end(way2));
			for(int x:way1)way.push_back(x);
			way.push_back(1);
			for(int x:way2)way.push_back(x);
			int L=way.size();
			vector<int>ok1={way[(L-1)/4],way[(L+3)/4]},ok2={way[L-1-(L-1)/4],way[L-1-(L+3)/4]};
			int ans=1e18;
			for(int u:ok1){
				int tmp=0;
				for(int v:ok2){
//					cout<<u<<" "<<v<<"\n";
					int tmp=0;
					F(i,1,n){
						if(i==u||i==v)continue;
						tmp=max(tmp,min(dis(i,u),dis(i,v)));
					}
					ans=min(ans,tmp);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<sqrt(n)<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
11 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11

0 1
7 2
1 2
1 3
2 4
2 5
3 6
3 7


*/
