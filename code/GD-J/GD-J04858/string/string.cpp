#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
unsigned long long s1,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],s1+=a[i];
	if(s1%2==0)
	{
		int x=0;
		for(int i=1;i<=n;i++)
		{
			s2+=a[i];
			if(s2>=(s1/2))
			{
				x=i;
				break;
			}
		}
		if(s2!=(s1/2))
		{
			for(int i=n+1;i>x+1;i--)
				a[i]=a[i-1],c[i]=c[i-1];
			a[x+1]=s2-(s1/2);
			c[x+1]=c[x];
			a[x]-=a[x+1];
			n++;
		}
	}
	else 
	{
		int x=0;
		for(int i=1;i<=n;i++)
		{
			s2+=a[i];
			if(s2>=(s1/2))
			{
				x=i;
				break;
			}
		}
		if(s2==(s1/2))
			a[x+1]--;
		else if(s2==(s1/2+1))
			a[x]--;
		else if(s2>(s1/2+1))
		{
			for(int i=n+1;i>x+1;i--)
				a[i]=a[i-1],c[i]=c[i-1];
			a[x+1]=s2-(s1/2+1);
			c[x+1]=c[x];
			a[x]-=a[x+1]+1;
			n++;
		}
	}
	int l=1,r=n;
	unsigned long long ll=a[l],rr=a[r],ans=0;
	char p=c[l],q=c[r];
	while(l<=r)
	{
		if(ll>rr)
		{
			ll-=rr;
			if(p!=q)
				ans+=rr;
			rr=a[--r];
			q=c[r];
		}
		else if(ll==rr)
		{
			if(p!=q)
				ans+=ll;
			ll=a[++l];
			rr=a[--r];
			p=c[l];
			q=c[r];
		}
		else
		{
			rr-=ll;
			if(p!=q)
				ans+=ll;
			ll=a[++l];
			p=c[l];
		}
	}
	cout<<ans;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
