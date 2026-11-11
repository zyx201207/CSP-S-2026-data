#include <bits/stdc++.h>
using namespace std;
string s;
char a;
long long n,sam,x,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cout<<s;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a;
		sam+=x;
		for(int j=1;j<=x;j++)
		{
			s+=a;
		}
	}
	if(sam%2==0)
	{
		long long l=sam/2-1,r=sam/2;
		for(int i=1;i<=sam/2;i++)
		{
			if(s[r]!=s[l])
			{
				sum++; 
			}
			r++;
			l--;
		}
	}
	else
	{
		long long l=sam/2-1,r=sam/2+1;
		for(int i=1;i<=sam/2;i++)
		{
			if(s[r]!=s[l])
			{
				sum++; 
			}
			r++;
			l--;
		}
	}
	cout<<sum;
	return 0;
 } 
