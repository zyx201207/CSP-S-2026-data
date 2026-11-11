#include<bits/stdc++.h>
using namespace std;
string s="";
long long n,cnt=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--) {
		int x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++) s+=c;
	}
	n=s.size();
	for(int i=0;i<n/2;i++) if(s[i]!=s[n-i-1]) cnt++;
	cout<<cnt;
	return 0;
}
