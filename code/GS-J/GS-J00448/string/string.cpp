#include <bits/stdc++.h>
using namespace std;
int main()
{ 
	int n,b[1005];
	int a,c;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		if(b[i] == a)
		{
			return 0;
		}
		else
		{
			int t=a;
			a=c;
			c=t;
		}
	}
	return 0;
}
