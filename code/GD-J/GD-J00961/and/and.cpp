#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,b[N],a[N],res,ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--)
	{
		res=0;
		for(int j=1;j<=n;j++)
		{ if(b[j]==0&&(a[j]&(1ll<<i))>0) res++;}
		if(res>=m)
		{
			for(int j=1;j<=n;j++){ if((a[j]&(1ll<<i))==0) b[j]=1;}
			ans+=(1ll<<i);
		}
	}
	cout<<ans;
	return 0;
}

