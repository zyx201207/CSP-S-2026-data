#include <bits/stdc++.h>
using namespace std;
char s[10000005]={0};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int c=0,p=0;
	long long maxx=0;
	for(int i=1;i<=a;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		maxx=max(maxx,x);
		for(int l=c+1;l<=c+x;l++)
		{
			s[l]=y;
			p++;
		}
		c+=x;
	}
	if(c%2==0)
	{
		long long cnt=0;
		long long d=0,e=c+1;
		for(int i=1;i<=(c-2);i++)
		{
			d++;
			e--;
			if(s[d]!=s[e]) cnt++;
		}
		cout<<min(c-maxx,cnt);
	}
	if(c%2==1)
	{
		long long cnd=0;
		long long f=0,g=c+1;
		for(int i=1;i<=(c-1)/2;i++)
		{
			f++;
			g--;
			if(s[f]!=s[g]) cnd++;
		}
		cout<<min(c-maxx,cnd);
	}
	return 0;
}
