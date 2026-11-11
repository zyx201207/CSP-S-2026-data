#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<n;i++){int opt;cin>>opt>>opt;}
	cout<<ceil(n-2.0)/k<<'\n';
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
} 
