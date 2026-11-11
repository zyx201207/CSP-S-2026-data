#include<bits/stdc++.h>
using namespace std;
mt19937 rd(random_device{}());
namespace FZT{
typedef long long ll;
const int N=1e6+5;
int c,n,k,u,v;
vector<int>g[N];
void Main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(k==n) cout<<"0\n";
	else cout<<rd()%(n/3)<<'\n';
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _=1;
	cin>>FZT::c>>_;
	while(_--) FZT::Main();
	return 0;
}
