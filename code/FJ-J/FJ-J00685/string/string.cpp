#include<bits/stdc++.h>
using namespace std;
string a[99999999];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s,j,p=0,q=0,sum=0;
	string b;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>s>>b;
		sum+=s;
		for(j=0;j<s;j++)
		{
			a[j+p]=b;
		}
		p=j;
	}
	for(int i=0;i<sum/2;i++)
	{
		if(a[i]==a[sum-i])
		q++;
	}
	cout<<q;
	return 0;
}
