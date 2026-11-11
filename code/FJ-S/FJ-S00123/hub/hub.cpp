#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k;
signed main(){ 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i<=n-1;i++){
			int x,y;
			cin>>x>>y;
		}
		cout<<max(n-2*k,2*k-n)<<"\n";
	}
	return 0;
}
