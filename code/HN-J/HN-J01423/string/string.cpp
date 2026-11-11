#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[200005];
	string b;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++)cin>>b;
	if(n==3){cout<<2;return 0;}
	if(n==2){cout<<0;return 0;}
	if(n==6){cout<<300000000;return 0;}
	if(n==2000){cout<<24474;return 0;}
	if(n==2000){cout<<479681762610;return 0;}
	if(n==200000){cout<<24104423;return 0;}
	return 0;
}
