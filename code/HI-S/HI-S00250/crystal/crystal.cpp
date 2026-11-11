#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,mi=1e15,id,cha[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >>m;
	for(long long i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		int x=abs((a[n]-a[i])-(a[i]-a[1]));
		if(x<=mi)
		{
			id=i;
			mi=x;
		}
	}
	for(long long i=1;i<id;i++)
	{
		cha[i]=a[id]-a[i];
	}
	sort(cha+1,cha+id+1);
	long long x=0,y=0;
	for(long long i=1; ;i++)
	{
		if(x+cha[i]>m)
		{
			cout <<y;
			return 0;
		}
		else if(x+cha[i]==m)
		{
			cout <<y+1;
			return 0;
		}
		else
		{
			x+=cha[i];
			y++;
		}
	}
	
}
