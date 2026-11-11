#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],k,h,l,hy,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	k=1,h=1,l=1;
	for(int i=1;i<=n;i++)
	{
		while((a[h+1]-a[h])*l+hy<=m && h<=n)
		{
			hy+=(a[h+1]-a[h])*l;
//			cout<<h<<" "<<hy<<" "<<a[h+1]<<" "<<a[h]<<endl; 
			l++;
			h++;
		}
//		cout<<l<<" "<<hy<<endl;
		ans=max(ans,l);
		hy-=a[h]-a[i];
		l--;
	}
	cout<<ans;
	return 0;
}
