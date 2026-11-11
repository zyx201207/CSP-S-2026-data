#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,l=0,cnt=0;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=1;i<=a;i++)
			s[++l]=c;
	}
	for(long long i=1;i<=l/2;i++)
		if(s[i]!=s[l-i+1])cnt++;
	cout<<cnt;
	return 0;
}
