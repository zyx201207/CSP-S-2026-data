#include<bits/stdc++.h>
using namespace std;
int d[2000001][2],val,id;
vector<int>s[2000001];
void dfs(int w,int fa,int de){
	d[w][0]=de;
	for(int i=s[w].size()-1;i>-1;--i){
		if(s[w][i]!=fa){
			dfs(s[w][i],w,de+1);
			if(d[s[w][i]][0]>d[w][0])
				d[w][1]=d[w][0],d[w][0]=d[s[w][i]][0];
			else if(d[s[w][i]][0]>d[w][1])
				d[w][1]=d[s[w][i]][0];
		}
	}
	if(d[w][1])
		if(d[w][1]+d[w][0]-2*de>val)
			val=d[w][1]+d[w][0]-2*de,id=w;
}
void sol(){
	int n,k,u,v;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		s[i].clear();
	for(int i=1;i<n;++i){
		cin>>u>>v;
		s[u].emplace_back(v),s[v].emplace_back(u);
	}
	if(n==k){
		cout<<0<<'\n';
		return;
	}
	if(n-1==k){
		cout<<1<<'\n';
		return;
	}
	cout<<(n-k)/2<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
		sol();
	return 0;
}
