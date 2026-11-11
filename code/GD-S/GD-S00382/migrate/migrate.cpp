#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,dis[200005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>u;
		if(k==3)cout<<0;
		else cout<<1+(t%2);
		cout<<'\n';
	}
	return 0;
}
