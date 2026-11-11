#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; string s="";
	cin>>n;
	while(n--) {
		int c; string a;
		cin>>c; cin>>a;
		while(c--) {
			s+=a;
		}
	}
	long long len=s.size(),ant=0;
	for(long long i=0;i<(len+1)/2;i++) 
		if(s[i]!=s[len-i-1]) ant++;
	cout<<ant;
	return 0;
}
