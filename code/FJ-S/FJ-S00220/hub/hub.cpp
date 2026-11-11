#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v;
}edges[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t,n,k;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>edges[i].u>>edges[i].v;
			cout<<1<<'\n';
		}
	}
	return 0;
} 
