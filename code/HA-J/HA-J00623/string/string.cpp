#include <bits/stdc++.h>
using namespace std;
struct huiwenshu
{
	long long x;
	char a;
}p[200000+10];
long long n,ji=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>p[i].x>>p[i].a;
	long long l=1,r=n;
	while(l<=r)
	{
		if(p[l].a!=p[r].a)	ji+=min(p[l].x,p[r].x);
		if(p[l].x==p[r].x)
		{
			r--;
			l++;
		}
		else if(p[l].x>p[r].x)
		{
			p[l].x-=p[r].x;	
			r--;
		}
		else if(p[l].x<p[r].x)
		{
			p[r].x-=p[l].x;	
			l++;
		}
	}
	cout<<ji;
	return 0;
} 
