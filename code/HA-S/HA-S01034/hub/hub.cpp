#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,b[1000010],f,d;
bool e[1000010];
vector<int> a[1000010];
void dfs(int x,int y){
	if(e[x]){
		return;
	}
	e[x]=1;
	b[x]=y;
	for(int i=0;i<a[x].size();i++){
		dfs(a[x][i],y+1);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1,0);
		sort(b+1,b+n+1);
		f=b[n]+b[n-1];
		cout<<f<<"\n";
	}
	return 0;
}
