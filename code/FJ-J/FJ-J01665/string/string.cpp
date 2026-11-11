#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j,l;
	cin>>l;
	string s;
	long long k=0;
	for(i=1;i<=l;i++)
	{
		long long zs;
		char zs1;
		cin>>zs>>zs1;
		for(j=0;j<zs;j++)
		{
			s[k]=zs1;
			//cout<<zs1;
			k++;
		}
	}
	long long ans=0;
	for(i=0;i<l/2+1;i++)
	{
		if(s[i]!=s[l-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
