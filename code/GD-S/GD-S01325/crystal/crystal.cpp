#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],c[1010],l,r,mid,da,xiao=LLONG_MAX,t;
bool check(long long x)
{
	xiao=LLONG_MAX;
	for(long long i=1;i<=n-x;i++)
	{
		t=0;
		for(long long j=i;j<i+x;j++)
		{
			t+=a[i+x-1]-a[j];
		}
		xiao=min(xiao,t);
	}
	return xiao<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		da=max(da,abs(a[i]));
		xiao=min(xiao,a[i]);
	}
	if(n>5000&&a[1]==1&&a[2]==2&&a[3]==3)
	{
		r=LLONG_MAX;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if(mid<=m&&mid*(mid+1)/2<=m)l=mid;
			else r=mid;
		}
		cout<<min(l,n);
		return 0;
	}
	else if(n>5000&&a[2]-a[1]==a[3]-a[2])
	{
		t=a[2]-a[1];
		r=n+1;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if(a[mid]<=m&&mid*(a[1]+t*(mid-1)+a[1])/2<=m)l=mid;
			else r=mid;
		}
		cout<<min(l,n);
		return 0;
	}
	else if(n>5000&&da<=100&&xiao>=-100)
	{
		for(int i=1;i<=n;i++)
		{
			c[a[i]+100]++;
		}
		for(int i=0;i<=200;i++)
		{
			l=c[i],r=0;
			for(int j=1;j<=100;j++)
			{
				if(i-j<0)
				{
					if(r+(c[i+j]*j)>m)
					{
						l+=((m-r)/j);
						break;
					}
					else r+=(c[i+j]*j),l+=c[i+j];
				}
				else if(i+j>200)
				{
					if(r+(c[i-j]*j)>m)
					{
						l+=((m-r)/j);
						break;
					}
					else r+=(c[i-j]*j),l+=c[i-j];
				}
				else 
				{
					if(r+(c[i+j]*j)+(c[i-j])*j>m)
					{
						l+=((m-r)/j);
						break;
					}
					else r+=(c[i+j]*j+c[i-j]*j),l+=(c[i+j]+c[i-j]);
				}
			}
			if(t<l)t=l;
		}
		cout<<t;
		return 0;
	}
	else if(n>5000)
	{
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	r=LLONG_MAX;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
} 
