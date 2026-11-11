#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5; 
const int inf=0x7f7f7f7f;
int siz[N];
int top[N];
int wc[N];
int fa[N];
int dep[N];
vector<int>a[N];
void dfs1(int u,int _fa){
	siz[u]++;dep[u]=dep[_fa]+1;fa[u]=_fa;
	for(int i=0;i<(int)a[u].size();i++){
		if(a[u][i]==_fa)continue;
		dfs1(a[u][i],u);
		siz[u]+=siz[a[u][i]];
		if(siz[a[u][i]]>siz[wc[u]])wc[u]=a[u][i];
	}
}
void dfs2(int u,int _fa,int Top){
	top[u]=Top;
	if(wc[u])dfs2(wc[u],u,Top);
	for(int i=0;i<(int)a[u].size();i++){
		if(a[u][i]==_fa)continue;
		if(a[u][i]==wc[u])continue;
		dfs2(a[u][i],u,a[u][i]);
	}
}
int lca(int x,int y){
	while(1){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		if(top[x]==top[y])return dep[x]>dep[y]?y:x;
		y=fa[top[y]];
	}
}
int dis(int x,int y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
int n,k;
vector<int>s;
int color[N];
int _fa[N];
int find(int x){
	if(_fa[x]==x)return x;
	return _fa[x]=find(_fa[x]);
}
bool check(){
	for(int i=0;i<=n;i++)_fa[i]=i;
	for(int i=0;i<(int)s.size();i++){
		int v=s[i];
		for(int j=0;j<(int)a[v].size();j++){
			if(color[a[v][j]]){
				_fa[find(v)]=find(a[v][j]);
			}
		}
	}
	set<int>st;
	for(int i=0;i<(int)s.size();i++)st.insert(find(s[i]));
	return (int)st.size()<=2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<=n;i++)a[i].resize(0),siz[i]=top[i]=dep[i]=wc[i]=fa[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs1(1,1);dfs2(1,1,1);
		int ans=inf;
		for(int msk=0;msk<(1<<n);msk++){
			int cnt=0;
			s.resize(0);
			for(int i=0;i<n;i++){
				if((msk>>i)&1)cnt++,color[i+1]=1,s.push_back(i+1);
				else color[i+1]=0;
			}
			if(cnt!=k)continue;
			if(!check())continue;
			int maxn=-inf;
			for(int i=1;i<=n;i++){
				if(color[i])continue;
				int minn=inf;
				for(int j=0;j<(int)s.size();j++){
					minn=min(minn,dis(i,s[j]));
				}
				maxn=max(maxn,minn);
			}
			ans=min(ans,maxn);
		}
		cout<<ans<<"\n";
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
*/
/*
203 ~ 215?

T1 18min
T2 1h
T3 乱搞
T4 暴力

T2 O(n^3+m(d^2))不知道能不能过 
快读居然没有cin快 
为什么试机的电脑CPU有3.1GHz，比赛的就只有2.2GHz,不都是同一个学校的吗 
T2大样例1.3s,评测机的 Ultra9应该能跑 

诈骗一下:
//freopen
feropen
bits\stdc++.h
#include<bits\stdc++.h>
mian
namesapce
nameaspce
freopen("hub2.in","r",stdin);
*/
