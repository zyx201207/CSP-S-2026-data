#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long x;
	char y;
}a[10000005];
long long n;
long long l=1;
long long r=0;
long long ss=0;
long long s=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].x >>a[i].y ;
	}
	while(r>l)
	{
		if(a[l].x>a[r].x )
		{
			ss=a[r].x ;
			a[l].x =a[l].x -a[r].x ;
			if(a[l].y !=a[r].y)
			{
				s=s+ss;
			}
			r--;
		}
		else if(a[l].x<a[r].x )
		{
			ss=a[l].x ;
			a[r].x =a[r].x -a[l].x ;
			if(a[l].y !=a[r].y)
			{
				s=s+ss;
			}
			l++;
		}
		else
		{
			ss=a[l].x ;
			if(a[l].y !=a[r].y)
			{
				s=s+ss;
			}
			l++;
			r--;
		}
	}
	cout<<s;
	return 0;
}
