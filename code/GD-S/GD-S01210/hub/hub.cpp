#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(k!=n) cout<<max(((n+1)/2-k)/4+1,1ll);
		else cout<<0;
		cout<<"\n";
	}
	return 0;
}
