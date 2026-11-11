#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,a[N],m,s[N];
bool check(int len)
{
	for(int i=1;i+len-1<=n;i++) if(a[i+len-1]*len-(s[i+len-1]-s[i-1])<=m) return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<max(0ll,r)<<endl; 
	return 0;
}
//给自己蠢哭了。看错题意+快读写炸
//预计：100pts 
