#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1,s2,c;
    int n,a[200001],b=0,d=0,x=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			b++;
			s1[b]=c[i];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			s2[b]=c[i];
			b--;
		}
	}
	for(int i=1;i<=n;i++)d+=a[i];
	for(int i=1;i<=d;i++)
	{
		if(s1[i]!=s2[i])x++;
	}
	cout<<x/2;
	return 0; 
} 
