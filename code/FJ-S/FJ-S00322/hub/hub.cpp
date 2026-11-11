#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k,ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		ans=k/2+1;
		cout << ans << '\n';
	}
	return 0;
}
