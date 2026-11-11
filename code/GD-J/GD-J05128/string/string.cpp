#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],k,ans,d[400010],t[200010];
char ch[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		d[i]=d[i-1]+a[i];
		t[i]=d[i];
	}
	for(int i=n;i>=1;i--)
		d[i+n]=d[i+n+1]+a[i];
	sort(d+1,d+1+2*n);
	for(int i=1;i<=2*n;i++)
	{
		if(d[i]==d[i-1])	continue;
		int l=1,r=n,p,q;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(t[mid]>=d[i])
			{
				p=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(t[mid]>=t[n]-d[i]+1)
			{
				q=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
//		cout<<d[i]<<" "<<p<<" "<<q<<endl;
		if(ch[p]!=ch[q])
		{
			ans+=d[i]-d[i-1];
		}
	}
	cout<<ans/2<<endl;
	return 0;
}
