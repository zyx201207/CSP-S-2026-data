#include<bits/stdc++.h>
using namespace std;
int n,k,dist[2000005],c,t,u[2000005],v[2000005];
struct node{
	int nxt;
	int to;
	int w;
}edge[2000005];
queue<int>q;
bool chk(int rt){
	for(int i=1;i<=n;i++){
		dist[i]*=rt+dist[i-1];
	return dist[n]%2==1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		dijkastra(1);
		cout<<dist[n]<<"\n";
	}
	return 0;
}

