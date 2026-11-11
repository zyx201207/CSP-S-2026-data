#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int a[N];
int n,m,ans;
int check(int x)
{
	int t=0,num=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x) break;
		if(t>m) 
		{
			ans=max(ans,num);
			return false;
		}
		t+=x-a[i];
		num++;
	}
	if(t<=m&&num>=ans)
	{
//		cout<<x<<" "<<num<<" "<<t<<endl;
		ans=max(ans,num);
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
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i) t++;
	}
	sort(a+1,a+n+1);
	if(t!=n)
	{
		int l=-1e18,r=1e18;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid))
			{
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans;	
	}
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(c>m)
		{
			cout<<i-1;
			break;
		}
		c+=a[i];
	}
	return 0;
}

