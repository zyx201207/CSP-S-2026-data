#include<bits/stdc++.h>
using namespace std;
int n,a;
long long sum;
string c,s,ss;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		ss+=s[i];
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(ss[i]!=s[i])
		{
			sum++;
		}
		
	}
	cout<<sum;
	return 0;
}
