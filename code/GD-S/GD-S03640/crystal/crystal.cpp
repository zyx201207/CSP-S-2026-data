#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++) 
#define dwn(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
const int N=5e5+5;
int a[N],n,m,s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int S=0,ans=0;
	rep(i,1,n)
	{
		int ls=m-i*a[i]-a[i]+s[i];
		int l=1,r=i,k=i;
		while(l<=r)
		{
			int j=l+r>>1;
			if(s[j-1]-j*a[i]<=ls) k=j,r=j-1;
			else l=j+1;
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
}
