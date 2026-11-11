#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+10;
struct node
{
	ll val;
	string c;
}a[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].val>>a[i].c;
	ll l=1,r=n,cnt_l=0,cnt_r=0,ans=0;
	while(l<r)
	{
		if(cnt_l>cnt_r)
		{
			if(a[l-1].c!=a[r].c) ans+=min(cnt_l-cnt_r,a[r].val);
			cnt_r+=a[r--].val;
		}
		else if(cnt_l<cnt_r)
		{
			if(a[l].c!=a[r+1].c) ans+=min(cnt_r-cnt_l,a[l].val);
			cnt_l+=a[l++].val;
		}
		else if(cnt_l==cnt_r)
		{
			if(a[l].c!=a[r].c) ans+=min(a[l].val,a[r].val);
			cnt_l+=a[l++].val;
			cnt_r+=a[r--].val;
		}
	}
	if(l>r)
	{
		if(cnt_l<cnt_r) ans+=((cnt_r-cnt_l)>>1ll)*(a[l].c!=a[r].c);
		else if(cnt_l>cnt_r) ans+=((cnt_l-cnt_r)>>1ll)*(a[l].c!=a[r].c);
	}
	else if(cnt_l<cnt_r) ans+=min(cnt_r-cnt_l,a[l].val)*(a[l].c!=a[r+1].c);
	else if(cnt_l>cnt_r) ans+=min(a[l].val,cnt_l-cnt_r)*(a[l-1].c!=a[r].c);
	cout<<ans;
	return 0;
}
