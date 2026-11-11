#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char c[maxn];
int n,ctl,ctr,a[maxn];
long long len,ans,beg[maxn],lst[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	ctl=1,ctr=n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		beg[i]=lst[i-1]+1;
		lst[i]=lst[i-1]+a[i];
	}
	long long l=1,r=len,mid=((len>>1)|1);
	while(l<r)
	{
		long long l_len=lst[ctl]-l+1,r_len=r-beg[ctr]+1;
		if(l_len<r_len)
		{
			ans+=(c[ctl]!=c[ctr])*l_len;
			l+=l_len;
			r-=l_len;
			++ctl;
		}
		if(l_len==r_len)
		{
			ans+=(c[ctl]!=c[ctr])*l_len;
			l+=l_len;
			r-=l_len;
			++ctl,--ctr;
		}
		if(l_len>r_len)
		{
			ans+=(c[ctl]!=c[ctr])*r_len;
			l+=r_len;
			r-=r_len;
			--ctr;
		}
	}
	cout<<ans;
	return 0;
} 
