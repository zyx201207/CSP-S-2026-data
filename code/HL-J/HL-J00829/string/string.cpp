#include<bits/stdc++.h>
using namespace std;
struct td
{
	long long wz,ok;
	char dc;
}a[1000005];
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
	long long n,cnt,op=0;
	string s,cmp;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].wz>>a[i].dc;
	}
	for(long long i=1;i<=n;i++)
	{
		cnt+=a[i].wz;
		a[i].ok=a[i].wz;
		while(a[i].wz>0)
		{
			a[i].wz--;
			s+=a[i].dc;
		}
	}
	for(long long i=n;i>=1;i--)
	{
		while(a[i].ok>0)
		{
			a[i].ok--;
			cmp+=a[i].dc;
		}
}
		if(cmp==s)
		  cout<<0;
	else
	{
		for(long long i=0;i<s.length();i++)
     	{
			if(cnt%2==0)
			{
				if(i<=cnt/2)
				{
						if(s[i]!=cmp[i])
				  op++;
				}
			}
			else
			{
				if(i<cnt/2)
				{
						if(s[i]!=cmp[i])
				  op++;
				}
			}
		}
		cout<<op;
	}
	
}