#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
long long n,m,maxn=0,main=0;
long long cnt=0;
lomg long cnt1=m;
bool check(long x,long long h,long long c)
{
	while(1)
	{
	if(c>x&&c<h)
	{
		c+cnt1=h;
		cnt1-=c;
	}
}
};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i];
		if(abs(a-b)<2&&a<b)
		{
			a[i]++;
			cnt1--;
			cnt+=2;
		}
		if(abs(a[i]-b[i])<2&&a[i]>b[i])
		{
			b[i]++;
			cnt1--;
			cnt+=2;
		}
		while(abs(a[i]-b[i])>=2)
		{
			a[i]=maxn;
			if(b[i]>maxn)
				b[i]=maxn;//juida
			else if(b[i]=maxn)
				main=a[i];
			else
				main=b[i];
			if(main+cnt1<maxn)
			{
				return 0;
			}
		long long l=1,r=2e9;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid))
			{
				l=mid-1;
				l++
			}
			else
			{
				r=mid-1;
				r--;
			}
		}
		}
	}
	cout<<cnt;
	return 0;
}
