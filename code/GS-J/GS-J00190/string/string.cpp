#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0,sum=0,m=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0)
		{
			cin>>num;
			cin>>s[i];
			for(int j=i+1;j<=num;j++)
			{
				s[j]=s[i];
			}
		}
		num=0;
	}
	sum=n/2;
	for(int i=sum+1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(s[i]=!s[j])
			{
				m++;
			}
		}
	}
	cout<<m;
	return 0;
}
