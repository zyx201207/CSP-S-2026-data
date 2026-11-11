#include <iostream>
#define int long long
#define mmx 200001
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct node{int l,r;char c;} lst[mmx];
signed main()
{
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,pl,pr,zl,zr,len=0,ans=0;
	cin>>n;
	fo (i,1,n)
	{
		cin>>lst[i].r>>lst[i].c;
		len+=lst[i].r;
		lst[i].l=lst[i-1].r+1;
		lst[i].r+=lst[i].l-1;
	}
	pl=1;pr=len;
	zl=1;zr=n;
	while (pl<=len/2)
	{
		if (lst[zl].r<pl) ++zl;
		if (lst[zr].l>pr) ++zr;
		if (lst[zl].c!=lst[zr].c) ++ans;
		++pl,--pr;
	}
	cout<<ans;
	return 0;
}
