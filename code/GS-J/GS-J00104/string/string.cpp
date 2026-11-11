#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	string s;
	for(int i=0; i<n; ++i) {
		long long a;
		string z;
		cin >> a >> z;
		for(int j=0; j<a; ++j) {
			s+=z;
		}
	}
	int l=s.size();
	string m;
	for(int i=l-1; i>=0; --i) {
		m+=s[i];
	}
	int ans=0;
	for(int i=0; i<l; ++i) {
		if(m[i]!=s[i]) ++ans;
	}
	printf("%d",ans/2);
	return 0;
}
