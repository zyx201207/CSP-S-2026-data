#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s,c;
	long long n,x=0,y=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int j;
		cin>>a[i]>>c[i];
		j=a[i];
		while(j!=0)
		{
			y++;
			s[y]=c[i];
			j--;
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(y%2==0)
	{
		for(long long i=y/2,j=y/2+1;i>=1&&j<=y;i--,j++)
		{
			if(s[i]!=s[j])
			{
				x++;
			}
		}
	}
	else
	{
		for(long long i=(y-1)/2,j=(y+3)/2;i>=1&&j<=y;i--,j++)
		{
			if(s[i]!=s[j])
			{
				x++;
			}
		}
	}
	cout<<x;
	return 0;
}
