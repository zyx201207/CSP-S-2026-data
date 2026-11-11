#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a,k,x;
string s;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n>10)
	{
		for(int i=0;i<n;i++)
		{
			cin>>c;
			s[i]=c;
			k++;
		}
		for(int i=0;i<k/2;i++)
		{
			if(s[i]!=s[n-i+1])
			{
				x++;
			}
		}
		cout<<x;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			s[k]=c;
			k++;
		}
	}
	for(int i=0;i<k/2;i++)
	{
		if(s[i]!=s[n-i+1])
		{
			x++;
		}
	}
	cout<<x;
	return 0;
}
