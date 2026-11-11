#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=1e6+5;
int c,t,n,k;
int sum[inf];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(sum,0,sizeof(sum));
		int mx=0;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			sum[u]++;
			sum[v]++;
			mx=max(mx,sum[u]);
			mx=max(mx,sum[v]);
		}
		if(mx>=k) cout<<1<<'\n';
		else cout<<2<<'\n';
	}
	return 0;
}
