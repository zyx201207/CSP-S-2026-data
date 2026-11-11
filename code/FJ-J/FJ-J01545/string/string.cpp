#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0,sum=0;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+='1';
	for(int i=1; i<=n; i++) {
		long long a;
		cin>>a;
		char c;
		cin>>c;
		ans+=a;
		for(int i=1; i<=a; i++)
			s+=c;
	}
	for(int i=1; i<=ans/2+1; i++) {
		if(s[i]!=s[ans-i+1]) sum++;
	}
	cout<<sum;
	return 0;
}
