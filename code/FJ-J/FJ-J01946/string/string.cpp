#include<bits/stdc++.h>
using namespace std;
long long n;
string s,b;
long long a;
long long ans=0;
long long sum=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a>>b;
		for(int i=1; i<=a; i++) {
			s+=b;
		}

	}
	sum=s.size()-1;
	for(int i=0; i<s.size()/2; i++) {
		if(s[i]!=s[sum-i]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

