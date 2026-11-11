//GZ-J00436 贵阳市花溪区实验中学 于靖恩 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long l=s.size();
	string c="";
	long long k=0;
	for(long long i=l-1;i>=0;i--)
	{
		c+=s[i];
	}
	for(long long i=0;i<(l+1)/2;i++)
	{
		if(c[i]!=s[i])
		{
			k++;
		}
	}
	cout<<k;
	return 0;
}
