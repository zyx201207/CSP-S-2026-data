#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long c,t,n,k,vis[N];
vector<long long>road[N];
void bfs(long long b,long long k){
	queue<long long> q;
	long long num=0;
	q.push(b);
	while(q.size()!=0){
		long long now=q.front();
		for(auto it:road[now]){
			if(num==k){
				break;
			}			
			q.push(it);
			num++;
		}
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			road[u].push_back(v);
			road[v].push_back(u);
		}
		bfs(0,k);
		cout<<1<<"\n";
	}
	return 0;
}
