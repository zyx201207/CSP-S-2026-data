#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	string s="";
	long long n,ans=0,cnt=0;
	cin>>n;
	for (int i=0;i<n;i++) {
		int a;
		char t;
		cin>>a>>t;
		while (a>0) {
			s+=t;
			a--;
		}
	}
	long long i=0,j=s.size()-1;
	while (i<=j) {
		if (s[i]!=s[j]) ans++;
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}
