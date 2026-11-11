#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
int n; 
ll m,a[N];
void solve() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,ans=0;
	ll now=0,len=0;
	for (int i=1;i<=n;i++)
	{
		while (a[i]*len-now>m) now-=a[l],len--,l++;
		ans=max(ans,i-l+1);
		now+=a[i],len++;
	}
	cout<<ans;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
