#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unsigned long long n,a,ans;
string s,st;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (unsigned long long i=1;i<=n;i++){
		cin>>a>>s;
		for (unsigned long long j=1;j<=a;j++){
			st+=s;
		}
	}
	n=st.length();
	for (unsigned long long i=0;i<n/2;i++){
		if (st[i]!=st[n-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
