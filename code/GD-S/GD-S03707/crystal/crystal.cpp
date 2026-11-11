#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],m,n,ans=-1;
int check(int k)
{
	int l=lower_bound(a+1,a+1+n,k)-a-1,r=upper_bound(a+1,a+1+n,k)-a;
	int ms=m,sq=0;
	sq=r-l-1;
	while(ms>=0)
	{
		bool bl=(l>=1),br=(r<=n);
		if(!bl&&!br)break;
		int tmpl=abs(k-a[l]),tmpr=abs(k-a[r]);
		if((tmpl<=tmpr&&bl)||(!br))l--,ms-=tmpl;
		else r++,ms-=tmpr;
		if(ms>=0)sq++;
		else break;
	}
	return sq;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	int maxn=a[1],minn=a[n];
	int l=maxn,r=minn;
	int p,da;
	p=da=0;
	for(int i=l;i<=r;i++)
	{
		int shul=check(i);
		if(shul>p)da=i;
		p=max(p,shul);
		
	}
	cout<<p;
	return 0;
}
