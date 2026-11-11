#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string sum=" ";
	for(int i=0; i<n; i++) {
		int a;
		char c;
		cin>>a>>c;
		for(int j=0; j<a; j++) {
			sum+=c;
		}
	}
	for(int i=1; i<=(sum.size()-1)/2; i++) {
		if(sum[i]!=sum[sum.size()-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
