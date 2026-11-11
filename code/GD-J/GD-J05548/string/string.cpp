#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],t,ans;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
	}

	t=n/2;
	for(int i=1; i<=t; i++) {
		if(s[n-i+1]!=s[i]) {
			if(i==t) ans=ans+max(a[i],a[n-i+1]);
			else ans=ans+min(a[i],a[n-i+1]);
		}
	}
	cout<<ans;
	return 0;
}
