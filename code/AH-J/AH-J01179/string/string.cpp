#include<bits/stdc++.h>
using namespace std;
long long n,L;
struct aa
{
	long long s,l,r,d;
	char c;
}a[1000005];
struct aa1
{
	long long l1,r1;
	char c1;
}a1[1000005];
struct aa2
{
	long long l2,r2;
	char c2;
}a2[1000005];
long long cmp1(aa1 x,aa1 y)
{
	return x.l1<y.l1;
}
long long cmp(aa x,aa y)
{
	return x.d<y.d;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
		a[i].l=L+1;
		L+=a[i].s;
		a[i].r=L;
	}
	for(long long i=1;i<=n;i++)
	{
		if(a[i].r<L/2)
		{
			a1[i].l1=L-a[i].r+1;
			a1[i].r1=L-a[i].l+1;
			a1[i].c1=a[i].c;
		}
		else if(a[i].r==L/2)
		{
			a1[i].l1=L-a[i].r;
			a1[i].r1=L-a[i].l+1;
			a1[i].c1=a[i].c;
		}
		else if(a[i].l<=ceil(L*1.0/2))
		{
			a1[i].r1=L-a[i].l+1;
			a1[i].l1=L/2;
			a1[i].c1=a[i].c;
			a2[i].r2=a[i+1].l-1;
			a2[i].l2=L/2;
			a2[i].c2=a[i].c;
		}
		else
		{
			a2[i].l2=a[i].l;
			a2[i].r2=a[i].r;
			a2[i].c2=a[i].c;
		}
	}
	sort(a1+1,a1+n+1,cmp1);
	long long aaa1=-1,aaa2=-1,ans=0;
	long long cnt=0;
	for(long long i=1;i<=n;i++)
	{
		if(a1[i].l1!=0)
		{
			if(aaa1==-1)
			{
				aaa1=i;
			}
			cnt++;
			a[cnt].d=a1[i].l1;
			cnt++;
			a[cnt].d=a1[i].r1;
		}
		if(a2[i].l2!=0)
		{
			if(aaa2==-1)
			{
				aaa2=i;
			}
			cnt++;
			a[cnt].d=a2[i].l2;
			cnt++;
			a[cnt].d=a2[i].r2;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	a[0].d=L/2;
	for(long long i=1;i<=cnt;i++)
	{
		char q,h;
		if(a[i].d>=a1[aaa1].l1&&a[i].d<=a1[aaa1].r1)
		{
			q=a1[aaa1].c1;
		}
		else
		{
			aaa1++;
			q=a1[aaa1].c1;
		}
		if(a[i].d>=a2[aaa2].l2&&a[i].d<=a2[aaa2].r2)
		{
			h=a2[aaa2].c2;
		}
		else
		{
			aaa2++;
			h=a2[aaa2].c2;
		}
		if(q!=h)
		{
			ans+=a[i].d-a[i-1].d;
		}
	}
	if(ans<0)
	{
		cout<<0;
		return 0;
	}
	cout<<ans;
}
