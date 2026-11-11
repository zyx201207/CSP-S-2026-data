#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
#define int long long
int n,len=0;
int a[200005],L[200005],R[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		L[i]=R[i-1]+1;
		R[i]=L[i]+a[i]-1;
		len+=a[i];
	}
	L[n+1]=len+1;
	int mid=(len+1)/2;
	int pos=-1;
	for(int i=1;i<=n;i++)
	{
		if(L[i]<=mid&&R[i]>=mid+((len&1)?0:1))
		{
			pos=i;
			break;
		}
	}
	int l,r;
	if(pos!=-1)
	{
		for(int i=n;i>=pos+1;i--)
		{
			a[i+1]=a[i],c[i+1]=c[i];
		}
		n++;
		if(len&1)
		{
			c[pos+1]=c[pos];
			a[pos]=mid-L[pos];
			a[pos+1]=R[pos]-mid;
			R[pos]=mid-1;
			L[pos+1]=mid+1;
		}
		else
		{
			c[pos+1]=c[pos];
			a[pos]=mid-L[pos]+1;
			a[pos+1]=R[pos]-mid;
			R[pos]=mid,L[pos+1]=mid+1;
		}
		l=pos,r=pos+1;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(R[i]<=mid&&L[i+1]>mid)
			{
				pos=i;
				break;
			}
		}
		l=pos,r=pos+1;
	}
	int ans=0;
	while(l>=1&&r<=n)
	{
		while(l>=1&&!a[l])
		{
			l--;
		}
		while(r<=n&&!a[r])
		{
			r++;
		}
		if(a[l]<a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			l--;
		}
		else
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			r++;
		}
	}
	printf("%lld",ans);
	return 0;
}
