#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int cntl=0,cntr=0;
	int l=1,r=n;
	int ans=0;
	while(l<r)
	{
		int ll=a[l]-cntl,lr=a[r]-cntr;
		if(c[l]==c[r])
		{
			if(ll<lr)
			{
				cntr+=ll;
				l++;
				cntl=0;
			}
			else if(ll>lr)
			{
				cntl+=lr;
				r--;
				cntr=0;
			}
			else
			{
				l++;
				r--;
				cntl=0;
				cntr=0;
			}
		}
		else
		{
			if(ll<lr)
			{
				cntr+=ll;
				ans+=ll;
				l++;
				cntl=0;
			}
			else if(ll>lr)
			{
				cntl+=lr;
				ans+=lr;
				r--;
				cntr=0;
			}
			else
			{
				l++;
				r--;
				cntl=0;
				cntr=0;
				ans+=ll;
			}
		}
	}
	cout<<ans;
	return 0;
}
