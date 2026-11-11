#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int a[N];
int n,m,ans;
int check(int x)
{
	int t=0,num=0,t1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			t1=i;
			break;
		}
	}
	for(int i=t1-1;i>=1;i--)
	{
		if(t>m)
		{
			if(ans<num)
			{
				ans=num;
				return true;
			}
			else return false;
		}
		num++;
		t+=x-a[i];
	}
	if(num>=ans)
	{
//		cout<<x<<" "<<num<<" "<<t<<endl;
		ans=num;
		return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
//	int n,m;
	cin>>n>>m;
//	int ans=0;
	int t=0; 
	int l=1e18,r=-1e18;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i) t++;
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	sort(a+1,a+n+1);
	while(l<=r)
	{
		int mid=(l+r)/2;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		if(check(mid))
		{
			l=mid+1;
//			c=mid;
		}
		else r=mid-1;
//		cout<<c<<" "<<ans<<endl;	
	}
	cout<<ans;
//	else
//	{
//		if(t==n)
//		{
//			int c=0;
//			for(int i=1;i<=n;i++)
//			{
//				if(c>m)
//				{
//					cout<<i-1;
//					break;
//				}
//				c+=a[i];
//			}
//		}
//	}
	return 0;
}

