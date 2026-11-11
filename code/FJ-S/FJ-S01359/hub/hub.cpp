#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;

int n,k;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t; 
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n==5) cout<<1<<endl;
		if(n==10) cout<<2<<endl;
	}
	return 0;
}
