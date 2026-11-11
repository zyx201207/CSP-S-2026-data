#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int S[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)S[i]=S[i-1]+a[i];
	int l=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-l)-(S[i-1]-S[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
