#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define of(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define N 210510
using namespace std;
int n,si;
ll ans,e;
char in;
struct node{
	ll l,r;
	char c;
}s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a;
	s[0].r=0;
	s[0].c='#';
	fo(i,1,n)
	{
		cin>>a>>in;
		if(in!=s[si].c)
		{
			s[++si].c=in;
			s[si].l=s[si-1].r+1;
			s[si].r=s[si-1].r+a;
		}
		else
		{
			s[si].r+=a;
		}
		e+=a;
	}
	for(int i=1,j=si;;)
	{
		ll l1=s[i].r-s[i].l+1,l2=s[j].r-s[j].l+1;
		char c1=s[i].c,c2=s[j].c;
		if(j<i) break;
		if(l1==l2)
		{
			if(c1!=c2)
			{
				ans+=l1;
			}
			++i;
			--j;
		}
		else if(l1>l2)
		{
			if(c1!=c2)
			{
				ans+=l2;
			}
			s[i].l+=l2;
			--j;
		}
		else if(l1<l2)
		{
			if(c1!=c2)
			{
				ans+=l1;
			}
			s[j].r-=l1;
			++i;
		}
	}
	cout<<ans;
	return 0;
}
