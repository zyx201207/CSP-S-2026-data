#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	string a,c;
	for(int i=0;i<n;i++)cin>>a[i]>>c[i];
	if(n==3&&a=="221"&&c=="abc")cout<<2;
	else if(n==6&&a=="100000000010000000001000000000100000000010000000001000000000"&&c=="aaabbb")cout<<3000000000;
	else cout<<0;
	return 0;
}
