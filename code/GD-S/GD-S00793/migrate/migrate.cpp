#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
struct edge{
	int v,w;
};
vector<edge>adj[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,cnt=0;
	cin>>c>>t;
	while(t--){
		cnt++;
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)adj[i].push_back({i+1,a[i+1]-a[i]});
		cout<<cnt<<endl;
	}
	return 0;
} 
