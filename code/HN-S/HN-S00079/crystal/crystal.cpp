#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=5e5+5;
int n,m,a[mx];
int ans;
int sum;
int l;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	for(int r=1;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m)
		{
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*

100pts 

*/


//许愿；希望能拿一等qwq  
