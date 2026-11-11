#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,mn=1e9;
vector<int> d[1000010];
int dfs(int x,int y){
	int mx=0,s=0;
	for(int i=0;i<d[x].size();i++){
		if(d[x][i]!=y){
			int m=dfs(d[x][i],x);
			mx=max(mx,m);
			s+=m;
		}
	}
	mx=max(mx,n-s-1);
	if(mx<mn){
		mn=mx;
	}
	mn=min(mn,mx);
	return s+1;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
    	cin>>n>>k;
    	for(int i=1;i<=n;i++){
    		int u,v;
    		cin>>u>>v;
    		d[u].push_back(v);
    		d[v].push_back(u);
		}
		mn=1e9;
		int g=dfs(1,0);
		cout<<mn<<endl;
	}
	return 0;
}

