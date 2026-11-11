#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],num=0,len=0;
char c[200005];
string s="",s2="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
			len++;
		}
	}
	for(int i=len-1;i>=0;i--)
	{
		s2+=s[i];
	}
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]!=s2[i])
		{
			num++;
		}
	}
	num/=2;
	cout<<num;
	return 0;
}
