#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l;	
	cin>>n;
	while(n--)
	{
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	long long k=0;
	for(int i=0,j=l-1;i<l/2,j>l/2;i++,j--)
	{
		if(s[i]!=s[j])
		{
			k++;
		}
	}
	cout<<k;
	return 0;
}

