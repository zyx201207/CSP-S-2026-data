#include<bits/stdc++.h>
using namespace std;
long long n;
struct node
{
	long long l,r,len;
	char idx;
}a[200005];
long long fid(long long idx)
{
	long long l=1,r=n,mid,ans=1;
	while(l<=r)
	{
//		cout<<"?";
		mid=(l+r)/2;
		if(a[mid].l<idx)
		{
			ans=mid;
			l=mid+1;
		}else
		r=mid-1;
	}
	return ans;
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
    	long long x;
    	cin>>x;
    	a[i].l=a[i-1].r+1;
    	a[i].r=a[i].l+x-1;
    	cin>>a[i].idx;
    	a[i].len=x;
	}
	long long ans=0,tot=a[n].r;
	for(long long i=1;i<=n;i++)
	{
		long long tl=tot-a[i].r+1,tr=tot-a[i].l+1;
		long long tidx=fid(tl);
		for(long long j=tidx;j<=n&&a[j].l<=tr;j++)
		{
			long long cmpl=max(tl,a[j].l),cmpr=min(tr,a[j].r);
			if(a[i].idx!=a[j].idx)
			{
				ans+=(cmpr-cmpl+1);
			}
		}
	}
	cout<<ans/2;
    return 0;
}
/*
2 
2 a 
3 a

3
2 a 
2 b
1 c

*/
