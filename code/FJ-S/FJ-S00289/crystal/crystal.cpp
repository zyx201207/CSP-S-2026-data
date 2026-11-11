#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
long long chaf[500005];
long long n,m;
bool check(int x)
{
	long long now=0;
	long long ans=0;
	for(int i=1;i<=x-1;i++)
	{
		now+=i*chaf[i];
		

	}

	ans=now;
	//n=5*10e5
	for(int i=x+1;i<=n;i++)
	{

		now=now-a[i-1]+a[i-x]+(x-1)*(chaf[i-1]);

		ans=min(ans,now);
		
	}

	if(ans>m)
	{
		return false;
	}
	else{
		return true;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	a[0]=0;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		chaf[i-1]=a[i]-a[i-1];
		
	}
	sort(a+1,a+n+1,less<long long>());
	for(int i=1;i<=n;i++)
	{
		chaf[i-1]=a[i]-a[i-1];
		
	}
	long long l=1,r=n,answ=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		//lg2 n=17
		if(check(mid)==true)
		{
			l=mid+1;
			answ=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<answ;
}
/*
5 8 -3 -1 2 2 7
*/
