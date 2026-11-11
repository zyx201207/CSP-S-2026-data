#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s,k;
	cin>>n>>s>>k;
	if(n==1)
	{
		cout<<0;
	}	
	
	if(n==2&&s==k)
	{
		cout<<0;
	}
	if(n==2&&s!=k)
	{
		cout<<1;
	}
	return 0;
}