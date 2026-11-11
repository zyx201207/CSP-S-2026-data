#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n,a,num=0,max=0;
	string s,c,sq,sh;
	cin>>n;
	if(n==1)max=0;
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			cin>>c;
			num+=a;
			for(int j=1;j<=a;j++)s+=c;
		}
		if(num%2==1)
		{
			for(int i=0;i<=num/2-1;i++)
			{
				sq+=s[i];
			}
			for(int j=num-1;j>num/2;j--)
			{
				sh+=s[j];
			}
			for(int z=0;z<num/2;z++)
			{
				if(sq[z]!=sh[z])max++;
			}
		}
		else
		{
			for(int i=0;i<num/2;i++)sq+=s[i];
			for(int j=num-1;j>num/2-1;j--)sh+=s[j];
			for(int z=0;z<num/2;z++)
			{
				if(sq[z]!=sh[z])max++;
			}
		}
	}
	cout<<max;
	return 0;
}
