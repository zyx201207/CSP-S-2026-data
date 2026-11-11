#include<bits/stdc++.h>
using namespace std;
long long n,a,b,d,mid,m,num;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool e=1;
	m=1;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		d+=a;
		for(long long j=b;j<d;j++)
		{
			s[j]=c;
		}
		b=d;
	}
	for(long long i=0;i<d;i++)
	{
		if(s[i]!=s[1])
		{
			e=0;
		}
	}
	if(d%2==0)
	{
		mid=d/2-1;
	}
	else
	{
		mid=d/2;
	}
	if(e==0)
	{
		for(long long i=mid+1;i<d;i++)
		{
			if(s[i]==s[i-mid*m]) 
			{
				m++;
				continue;
			}
			else
			{
				s[i]=s[i-mid*m];
				m++;
				num++;
			}
		}
		cout<<num;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
