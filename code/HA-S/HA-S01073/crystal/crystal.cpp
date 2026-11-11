#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int f[500010];
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=l+r>>1;//选从i向左共mid个
			int need=a[i]*mid;
//			cout<<need<<' '<<(f[i]-f[i-mid])<<' '<<mid<<endl;
//			cout<<l<<' '<<r<<endl;
			if(need-(f[i]-f[i-mid])>m)
				r=mid-1;
			else 
			{
				if(l==mid)
				{
//					need=a[i]*(l+1);
//					if(need-(f[i]-f[i-mid-1]))l++;
					if(need-(f[i]-f[i-r])<=m)l=r;
					break;
				}
				l=mid;
			}
		}
		int need=a[i]*l;
		if(need-(f[i]-f[i-l])>m)l--;
//		cout<<l<<endl;
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}   