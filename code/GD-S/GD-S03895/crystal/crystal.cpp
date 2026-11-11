#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int pre[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=a[i]+pre[i-1];
	int ans=1,lst=1;
	for(int i=2;i<=n;i++)
	{
		while(a[i]*(i-lst+1)-(pre[i]-pre[lst-1])>m) lst++;
		ans=max(ans,i-lst+1);
	}
	cout<<ans;
	return 0;
}
