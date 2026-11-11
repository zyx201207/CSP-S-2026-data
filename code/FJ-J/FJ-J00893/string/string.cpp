#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long n,ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		char c;
		int a;
		cin>>a>>c;
		for(long long j=1; j<=a; j++) {
			s2+=c;
		}
	}
	s1=s2;
	reverse(s2.begin(),s2.end());
	if(s1==s2) {
		cout<<0;
		return 0;
	}
	long long len=s1.size();
	long long z=(len+1)/2-1;
	for(long long i=0,j=len-1; i<=z,j>=z; i++,j--) {
		if(s1[i]!=s1[j]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
