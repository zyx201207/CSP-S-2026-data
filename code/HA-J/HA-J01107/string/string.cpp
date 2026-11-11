#include <bits/stdc++.h>
using namespace std;
long long n,g=0,r=0,sum=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		int t;
		char c;
		scanf("%d",&t);
		scanf("%c",&c); 
		for(int j=g;j<t+g;j++)
		{
			s[j]=c;
		}
		sum+=t;
	}
	sum=sum/2-1;
	for(int i=0;i<sum/2;i++)
	{
		if(s[i]!=s[sum-i])
		{
			r++;
		}
	}
	cout<<r;
	return 0;
}

