#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
long long n,m,d[N],s[N],a[N],t[N],op,ans;
//bool check(long long x,long long k)
//{
//	return s[x]-s[k]-t[k-1]*(a[x]-a[k])>m;
//}
long long find(long long x)
{
	long long l=0,r=x+1;
	while(r-l>1)
	{
		long long mid=(l+r)>>1;
		if(s[x]-s[mid]-t[mid-1]*(a[x]-a[mid])>m)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	return r;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>d[i];
	}
	sort(d+1,d+n+1);
	long long i_=1;
	while(i_<=n)
	{
		long long cnt=0;
		while(d[i_+1]==d[i_])
		{
			i_++;
			cnt++;
		}
		a[++op]=d[i_];
		t[op]=t[op-1]+cnt+1;
		i_++; 
	}
	for(long long i=1;i<=op;i++)
	{
		s[i]=s[i-1]+t[i-1]*(a[i]-a[i-1]);
		long long o=find(i);
//		cout<<o<<" "<<(o==1?0:(m-(s[i]-s[o]-t[o-1]*(a[i]-a[o])))/(a[i]-a[o-1]))+t[i]-t[o-1]<<endl;
		ans=max(ans,(o==1?0:(m-(s[i]-s[o]-t[o-1]*(a[i]-a[o])))/(a[i]-a[o-1]))+t[i]-t[o-1]);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

*/
