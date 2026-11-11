#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int n,ans;
ll m,a[500005],w;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	for(register int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	register int cnt = 1;
	for(register int i=2;i<=n;i++)
	{
		w+=(a[i]-a[i-1])*cnt;
		cnt++;
		if(w>m)
			for(;w>m;cnt--)
				w-=a[i]-a[i-cnt+1];
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}
