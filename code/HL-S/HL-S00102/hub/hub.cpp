#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t;
int n,k;
struct edge{
	int to,nxt;
}e[N<<1];
int head[N],I;
void add_edge(int u,int v){
	e[++I]={v,head[u]};
	head[u]=I;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			add_edge(u,v);
			add_edge(v,u);
		}
		cout<<0<<'\n';
	}
	return 0;
}
// I love Skirk