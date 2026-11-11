#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,a[MAXN],ans=0;
char c[MAXN];
string s="",t;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for (long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	t=s;
	reverse(t.begin(),t.end());
	for (long long i=0;i<s.length();i++){
		if (s[i]!=t[i]) ans++;
	}
	ans/=2;
	cout<<ans;
	return 0;
}
