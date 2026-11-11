#include<bits/stdc++.h>
using namespace std;
string s,c;
long long a,n,l,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			s+=c;
		}
	}
	l=s.size();
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
