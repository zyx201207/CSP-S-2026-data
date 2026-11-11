#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ma,sum,sh,d,a[5000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	//int mid=(n+1)/2;
	sum=0,sh=1,ma=1,d=1;
	for(int i=2;i<=n;i++)
	{
		int e=sum+sh*(a[i]-a[i-1]);
		if(e<=m) sh++,ma=max(ma,sh),sum=e;
		else
		{
			sh++;
			while(e>m) e-=a[i]-a[d],d++,sh--;
			ma=max(ma,sh),sum=e; 
		}
	}
	cout<<ma;
	return 0;
}
/*
13 2
-9 -7 -6 -5 -2 0 0 2 4 8 11 14 14
*/
