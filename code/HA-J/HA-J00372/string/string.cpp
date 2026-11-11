#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai,num=0;
	
	string ci,si,s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ai>>ci;
		for(int j=1;j<=ai;j++)
		{
			s+=ci;
			num++;
		}
		
	}
	int mis=0;
	for(int i=0;i<=num/2;i++)
	{
		if(s[i]!=s[num-1-i])
		{
			mis++;
		}
	}
	cout<<mis;
	if(n==1)
	{
		cout<<0;
	}
	
	return 0;
}
