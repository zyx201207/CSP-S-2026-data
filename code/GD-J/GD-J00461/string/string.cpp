//T2 string
#include <iostream>
#include <string>
using namespace std;
long long n,len=0;
string s="";
long long solve(string str) {
	long long cnt=0;
	if (len%2) {
		for (int i=0;i<=len/2;i++) {
			if (str[i]!=str[len-i-1]) cnt++;
		}
	}
	else {
		for (int i=0;i<=len/2-1;i++) {
			if (str[i]!=str[len-i-1]) cnt++;
		}
	}
	return cnt;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for (int i=0;i<n;i++) {
		long long x;
		char y;
		cin>>x>>y;
		len+=x;
		while (x--) {
			s+=y;
		}
	}
	cout<<solve(s);
	return 0;
}
