#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define fi first
#define se second
#define be begin()
#define en end()
#define CCF
#define dui
#define che
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;
const int inf=1e12;
int n,m,a[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef dui
	freopen(".out","r",stdin);
	freopen(".out","w",stdout);
#endif
#ifndef che
	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
#endif
#ifdef CCF
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1,cnt=0,l=1;
	for(int i=2;i<=n;i++)
	{
		while(cnt+(i-l)*(a[i]-a[i-1])>m) 
		{
			cnt-=a[i-1]-a[l];
			l++;
		}
		cnt+=(i-l)*(a[i]-a[i-1]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
//cout<<fixed<<setprecision(10);
//printf("%,3f,);
//5 5
//1 2 4 8 9
