#include<iostream>
#include<cstdio>
using namespace std;

long long n;
long long a[200005],b[200005]; char c[200005];
long long cnt,pos,mid,r,l;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		b[i]=a[i]+b[i-1];
	}
	mid=(b[n]+1)/2;
	for(long long i=1;i<=n;i++)
		if(b[i]>=mid)
		{
			pos=i;
			break;
		}
	r=n;
	l=1;
	while(l<r&&r<=n&&l>0&&l<=pos&&r>=pos)
	{
		if(a[r]>a[l])
		{
			if(c[r]!=c[l])
			{
				cnt+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else if(a[r]<a[l])
		{
			if(c[r]!=c[l])
			{
				cnt+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else
		{
			if(c[r]!=c[l])
			{
				cnt+=a[l];
			}
			a[l]=0;
			a[r]=0;
			r--;l++;
		}
	}
	cout<<cnt;
}
