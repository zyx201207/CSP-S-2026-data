#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>0;i--)
		b[i]=b[i+1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-ans;
		while(l<=r)
		{
			int j=l+r>>1;
			if(a[i]*(i-j)-b[j]+b[i]<=m)
				ans=max(ans,i-j+1),
				r=j-1;
			else
				l=j+1;
		}
	}
	cout<<ans;
	return 0;
}
