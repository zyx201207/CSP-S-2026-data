#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		cout<<k<<"\n";
	}
	return 0;
} 
