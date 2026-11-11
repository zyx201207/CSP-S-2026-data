#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
int n;
ll ans,a[N+5];
char c[N+5];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r]) a[l]-=a[r],r--;
		else if(a[l]<a[r]) a[r]-=a[l],l++;
		else l++,r--;
	}
	cout<<ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;//cin>>_;
	while(_--) solve();
	return 0;
}// CSP2026-J/S RP++
