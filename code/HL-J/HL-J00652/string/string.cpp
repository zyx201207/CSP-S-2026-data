#include<bits/stdc++.h>
using namespace std;
int a[100010];
char c[100010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;

	char l,r;
	bool flag=1;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{

		cin>>a[i]>>c[i];

		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}



	int len=s.size();
	int len1=len/2;
	for(int i=0;i<len-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<=len1;i++)
	{
		l=s[i];
		r=s[len-i];
		if(l!=r)
		{
			cnt++;
			s[len-i]=s[i];
		}
	}
	cout<<cnt;
	return 0;
}
