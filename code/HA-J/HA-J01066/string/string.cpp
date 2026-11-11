#include<bits/stdc++.h>
using namespace std;
long long s[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,z=0,k=0;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		for(int i=1;i<=a;i++)
		s[k++]=b;
	}
	for(int i=0;i<=n/2;i++)
	{
		if(s[i]!=s[n-i])
		{
			z++;
		}
	}
	cout<<z;
	return 0;
}

