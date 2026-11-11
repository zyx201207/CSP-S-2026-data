#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(i) cout<<"Debug "<<i<<' '
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define sc second 
const int N=1e6+10;
int n,a[N],s[N],m,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<r)
		{
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
		//debug(i)<<l<<' '<<a[i]<<'\n';
	}
	cout<<ans;
 } 
