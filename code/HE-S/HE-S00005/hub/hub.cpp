//17:23 baiqiyan ci yu wo tan xin de li liang1 /fn/fn/fn/fn
//zhao huan Bai Qi Yan tan xin zhi shen/fn/fn/fn/fn/fn
//What Can I Say!!!!!!!
//Wo de tong xue dou zai wai mian deng wo hui jia ne!!!!!!!
//Zai rang wo shuai hui shuai ba!!!!!!!
//17:37 wo chovy wo du cuo ti le QAQ
#include<bits/stdc++.h>
using namespace std;
const int N=4e6;
int c,T,n,k,siz[N],dep[N],mins;
vector<int>g[N],p;
inline void dfs(int u,int fa){
	int w=0;
	for(int i=0;i<(int)g[u].size();++i){
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		w=max(w,siz[v]);
	}
	mins=w=max(w,n-siz[u]);
	if(w<=(n+1)/2)p.push_back(u);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)g[i].clear(),siz[i]=0;
		mins=1e9;
		p.clear();
		for(int x,y,i=1;i<n;++i){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		cout<<mins<<'\n';
	}
	return 0;
}
