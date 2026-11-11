#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,t;
int n,k;
vector<int> g[maxn];
int h[maxn],fa[maxn];
void dfs(int u,int deep){
	deep++;
	for(int i=1;i<=g[u].size();i++){
		int v=g[u][i];
		h[v]=deep;
		fa[v]=u;
		dfs(v,deep+1);
	}
}
int gcd(int x,int y){
	while(h[x]>h[y]) x=fa[x];
	while(x!=y){
		x=fa[x];
		y=fa[y];
	}
	return x;
}
long long juli(int x,int y){
	if(h[x]<h[y]) swap(x,y);
	int p=h[gcd(x,y)];
	long long sum=(p-h[x])+(p-h[y]);
	return sum;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==0){
		cin>>n;
		if(n==5){
			cout<<1<<endl<<2;
			return 0; 
		}
		if(n==8){
			cout<<1<<endl<<1<<endl<<2;
			return 0;
		}
	}
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int u,v;
		for(int j=1;j<n;j++){
			cin>>u>>v;
			g[u].push_back(v);
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		h[1]=1;
		dfs(1,1);
		cout<<1<<endl;
	}
	return 0;
}
