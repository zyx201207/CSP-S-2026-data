#include<bits/stdc++.h>
using namespace std;
int const N=1e6;
int n;
int s[N];
string v[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0,l,r,p,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		scanf("%s",&v[i]);
	}
	l=1,r=n;
	p=s[1],t=s[n];
	while(l<r)
	{
		if(p>t)
		{
			if(v[l]!=v[r]) ans=ans+t;
			r--;
			p=p-t;
			t=s[r];
		}
		if(p<t)
		{
			if(v[l]!=v[r]) ans=ans+p;
			l++;
			t=t-p;
			p=s[l];
		}
		if(p==t)
		{
			if(v[l]!=v[r]) ans=ans+p;
			l++;
			r--;
			t=s[l];
			p=s[l];
		}
	}
	printf("%lld",ans);
	return 0;
}
