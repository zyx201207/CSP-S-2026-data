#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long L=0;
	string s;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		L+=a[i];
		while(a[i]--) {
			s+=c[i];
		}
	}
	long long ans=0;
	for(int i=0; i<((L+1)/2); i++) {
		if(s[i]!=s[L-1-i]) {
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
