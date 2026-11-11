#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
long long n,m,ans=1;
long long a[MAXN],cha[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	/*for (int i=0;i<n;i++)
	{
		printf("%lld ",a[i]);
	}*/
	for (int i=1;i<n;i++)
	{
		cha[i]=cha[i-1]+i*(a[i]-a[i-1]);
	}
	for(long long l=0,r=1;l<n;l++)
	{
		if (l==r&&r<n)
		{
			r++;
		}
		while (r<n&&(cha[r]-cha[l]-l*(a[r]-a[l])<=m))
		{
			ans=max(ans,r-l+1);
			r++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
1
5 5
1 2 4 8 9

2
5 8
-3 -1 2 2 7
*/
