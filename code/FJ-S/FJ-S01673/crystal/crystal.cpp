#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+6;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int zz=1,sum=0,ans=0;
	for(int i=1;i<=n;sum-=a[zz]-a[i],i++)
	{
		while(zz<n)
		{
			int xin=sum+(a[zz+1]-a[zz])*(zz-i+1);
			if(xin<=m) sum=xin,zz++;
			else break;
		}
		ans=max(ans,zz-i+1);
	}
	cout<<ans;
	return 0; 
}
