#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,k,c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int cty,cty1;
		for(int i=1;i<n;i++){
			cin>>cty>>cty1;
		}
		cout<<(n/2-k+4)/4+1<<"\n";	
	}
	
	return 0;
}

