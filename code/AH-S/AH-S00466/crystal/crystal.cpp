//crystal.cpp,1s,1024MiB
#include<bits/stdc++.h>
using namespace std;
#define int long long
//the eaziest T1 in recent 3 years
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	vector<int>a(n),sumf(n+1);
	for(auto &e:a)
		cin>>e;
	sort(a.begin(),a.end());
	int _m=*min_element(a.begin(),a.end());
	for(auto &e:a)
		e-=_m;//then a[0] becomes 0
	for(int i=1;i<=n;i++)
	{
		sumf[i]=sumf[i-1]+a[i-1];
		int l=1,r=i-1,pos=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i-1]*(i-mid+1)-sumf[i]+sumf[mid-1]<=m)
			{
				pos=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
}
