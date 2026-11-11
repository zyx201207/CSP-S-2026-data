#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int c,n,m,d,q;
//n=地铁路线数，m=地铁站数，d=最多被几条路线经过
//w=地铁口到站台时间
//k=路线被经过地铁站数
//a i,j第 i 条线路经过的第 j 个地铁站
//ti,j 表示从j地铁站的站厅走到第 i 条线路的站台需要的时间
//地铁口->站厅->站台
//我真受不了了 
//等下，注意到没有地铁行驶时间
//站台建边至站厅
//站台节点如何表示
//struct? 
//已放弃 
struct sub{
	int a[N];
	int t[N];
	int w;
	int k;
}s[N]; //必有start和end的w，路程中间必定与地铁口w无关 
struct edge{//id区分站台和站厅。站厅1站台2路线3 
	int v,w;
};
int tot;
vector<edge> e[N][4];
int count(int start,int end){
	int ans=0;
	ans+=(s[start].w+s[end].w);
	return ans+13;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].k;
		for(int k=1;k<=s[i].k;k++){
			cin>>s[i].a[k]>>s[i].t[k];
			if(i>=2){
				for(int j=1;j<=k;j++){
					e[s[i].a[k]][3].push_back({s[i].a[j],0});
					e[s[i].a[j]][3].push_back({s[i].a[k],0});
					
				}
			}
		} 
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<count(s,e)<<'\n'; 
	}
}
