#include <bits/stdc++.h>
using namespace std;
long long n,len,ans;
struct node
{
	long long sum;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].sum>>a[i].c;
		len+=a[i].sum;
	}
	long long l=1,r=n,mid=len/2,k=0;
	long long fn=a[l].sum,sn=a[r].sum;
	char fc=a[l].c,sc=a[r].c;
	while(l<=r)
	{
		if(fn==sn)
		{
			if(fc!=sc) ans+=fn;
			k+=fn;
			l++;
			r--;
			fn=a[l].sum,sn=a[r].sum;
			fc=a[l].c,sc=a[r].c;
		}
		else
		{
			if(fn>sn)
			{
				if(fc!=sc) ans+=sn;
				fn-=sn;
				k+=sn;
				r--;
				sn=a[r].sum;
				sc=a[r].c;
			}
			else
			{
				if(fc!=sc) ans+=fn;
				sn-=fn;
				k+=fn;
				l++;
				fn=a[l].sum;
				fc=a[l].c;
			}
		}
		if(k>=mid) 
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
