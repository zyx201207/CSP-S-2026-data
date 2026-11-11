#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(n==k) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
//must be tarjan
//i'm zb


