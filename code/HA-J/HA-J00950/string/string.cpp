#include<bits/stdc++.h>
using namespace std;
string s,c;
int a[1000],t,t1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		for(int j=t;j<=t+a[i];j++)
		{
			c[j]=s[i];
		}
		t=t+a[i];
	}
	for(int i=t,j=1;i>=t/2,j<=t/2;--i,++j)
	{
		if(c[i]!=c[j])
		{
			t1++;
		}
	}
	if(t%2==0)
	{
		t1=t1+1;
	}
	cout<<t1;
	return 0;
}
