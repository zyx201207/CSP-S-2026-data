#include<bits/stdc++.h>
using namespace std;
long long n,sp1,ep1,sp2,ep2,p1,p2,cnt;
long long a[200005];
long long s[200005],e[200005];
char c[200005];
long long l,zl;
int main(void)
{
	//string
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i]=l+1;
		l=l+a[i];
		e[i]=l;
	}
	zl=l/2;
	sp1=s[1];
	ep1=e[1];
	sp2=s[n];
	ep2=e[n];
	p1=1;
	p2=n;
	while(p1<=n && p2>=1)
	{
		long long ll1,ll2;
		ll1=ep1-sp1+1;
		ll2=ep2-sp2+1;
		if(ll1>ll2)
		{
			if(c[p1]!=c[p2])cnt=cnt+ll2;
			sp1=sp1+ll2;
			p2--;
			sp2=s[p2];
			ep2=e[p2];
		}
		else if(ll2>ll1)
		{
			if(c[p1]!=c[p2])cnt=cnt+ll1;
			ep2=ep2-ll1;
			p1++;
			sp1=s[p1];
			ep1=e[p1];
		}
		else
		{
			if(c[p1]!=c[p2])cnt=cnt+ll1;
			p1++;
			sp1=s[p1];
			ep1=e[p1];
			p2--;
			sp2=s[p2];
			ep2=e[p2];
		}
	}
	cout<<cnt/2;
	return 0;
}
