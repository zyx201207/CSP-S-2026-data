#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,s,t,c,d,q,x[500005];

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c >> t;
	while(t--){
		cin >> n >> k;
		for(int i =1;i<n;i++)cin >> q >> d;
		if(k&1)k++;
		cout << k/2<<"\n";
	}  
	return 0;
}
