#include<bits/stdc++.h>
using namespace std;

const int MXN = 5e5+3 , MXM = 3e5+3 ;

vector<int> g[MXN];
int n,m,a[MXN],w[MXM],ans[MXM];

void dfs(int c){
	ans[c]=w[c];
	for(int i:g[c]){
		dfs(i);
		ans[c]+=ans[i];
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i;i--){
		if(!w[a[i]])
			g[a[i+1]].push_back(a[i]);
		w[a[i]]++;
	}
	dfs(0);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}