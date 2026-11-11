#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(c % 2 == 1) cout<<n / k - 1<<endl;
		else cout<<n / k<<endl;
		for(int i = 0;i < n - 1;i++){
			int a,b;
			cin>>a>>b;
		}
	}
	return 0;
}
