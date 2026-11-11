#include <bits/stdc++.h>
using namespace std;
struct node{
	int idx;
	int x;
	int ti;
};
int c,n,m,d,q,s,e;
long long minn;
int w[500001],k[501],fa[500001],t[501][500001]; 
int a;
vector<node> g[500001];
void dfs(int idd,int u,long long ans){
	if(u==e){
		ans+=(w[e]+t[idd][e]);
		minn=min(minn,ans);
		return ;
	}
	for(auto i:g[u]){
		if(idd!=i.idx){
			dfs(i.idx,i.x,(ans+t[idd][u]+t[i.idx][u]));
		}else{
			dfs(i.idx,i.x,ans);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int la=0;
		for(int j=1;j<=k[i];j++){
			cin>>a>>t[i][a];
			g[la].push_back({i,a,t[i][a]});
			fa[a]=la;
			la=a;
		}
	}
	while(q--){
		cin>>s>>e;
		if(s>e){
			swap(s,e);
		}
		minn=LLONG_MAX;
		for(auto i:g[fa[s]]){
			if(i.x==s){
				dfs(i.idx,s,w[s]+t[i.idx][s]);
			}
		}
		cout<<minn<<endl;
	}
	return 0;
} 
/*
²âÊÔÑùÀý 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
