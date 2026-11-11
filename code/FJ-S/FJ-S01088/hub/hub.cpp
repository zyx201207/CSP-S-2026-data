#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,k;
vector<int>e[N];
int maxd,maxp;
void dfs1(int u,int fa,int len){
	if(len>maxd)maxd=len,maxp=u;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs1(v,u,len+1);
	}
}
int f[N];
void dfs2(int u,int fa,int len){
	f[u]=fa;
	if(len>maxd)maxd=len,maxp=u;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs2(v,u,len+1);
	}
}


void mian(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int p1,p2;
	dfs1(1,0,0);
	p1=maxp,maxd=0;
	dfs2(p1,0,0);
	p2=maxp;
	
}
int main(){
	ios::sync_with_stdio(0);
	int gm,T;cin>>gm>>T;
	while(T--)mian();
	return 0;
}
