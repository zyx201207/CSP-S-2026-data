#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		if(n>k){
			cout<<k-1<<endl;
		}
		else cout<<n-1<<endl;
	}
	return 0;
} 
