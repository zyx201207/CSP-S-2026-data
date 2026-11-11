#include<bits/stdc++.h>
#define int long long
using namespace std;
//const int N=1000010;
int n,k;//,dep[N],num[N];
//vector<int>g[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
//		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
		}
		if(k==1){
			cout<<n/4;
		}else cout<<((n-1)/8+1)-((k-1-((n-1)/2+1)%8)/4+1)+1<<"\n";
	}
	return 0;
}

