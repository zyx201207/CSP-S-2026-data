#include <bits/stdc++.h>
using namespace std;
long long n,a,ll,ans;
char c;
string s; 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a>>c;
		for (int j=1;j<=a;j++) {
			s+=c;
		}
	}
	ll=s.size();
	for (int i=0;i<ll/2;i++) {
		//cout<<i<<" "<<ll-1-i<<" "<<s[i]<<" "<<s[ll-1-i]<<endl;
		if (s[i]!=s[ll-1-i]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
