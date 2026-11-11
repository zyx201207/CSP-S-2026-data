#include<bits/stdc++.h>
using namespace std;
int a[200005];
char cc[200005];
string c;
int main()
{
	freopen("string.in","r",stdin);                                                                                                             
	freopen("string.out","w",stdout);                                                                                                           
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long T,s=0,x=0;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
			cin>>a[i]>>cc[i];
			s+=a[i];
			for(int j=1;j<=a[i];j++)
			{
					c+=cc[i];
			}
	}
	if(s%2==0)
	{
		for(int i=0;i<=s/2-1;i++)
		{
			if(c[i]!=c[s-i-1])
			{
				x++;
			}
		}
	}
	else
	{
		for(int i=0;i<=(s-1)/2-1;i++)
		{
			if(c[i]!=c[s-i-1])
			{
					x++;
			}
		}
	}
	cout<<x;
	return 0;
}
