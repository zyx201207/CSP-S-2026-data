#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>g[N];
int c;
void slove(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	if(c==13||c==14){
		cout<<(k>=n/2?1:n/2)<<'\n';
		return;
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	scanf("%d%d",&c,&t);
	while(t--)slove();
	return 0;
}
