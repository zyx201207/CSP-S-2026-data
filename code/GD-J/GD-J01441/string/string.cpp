#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200005];
ll cnt[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	memset(cnt,0,sizeof(cnt));
	for(register int i=1;i<=n;i++)
	{
		cin >> a[i] >> s[i];
		cnt[i] = cnt[i-1] + a[i];
	}
	ll ans = 0;
	for(register int i = 1, j = n;cnt[i-1]<(cnt[n]>>1);i++)
	{
		if(cnt[i]>=(cnt[n]>>1))
			a[i]-=cnt[i]-(cnt[n]>>1);
		while(j>=i&&cnt[n]-cnt[j]<=cnt[i]&&a[i]!=0)
		{
			int k=min(a[i],a[j]);
			if(s[i]!=s[j])
			{
				ans+=k;
			}
			a[i]-=k;
			a[j]-=k;
			if(a[j]==0) j--;
		}
	}
	cout << ans;
	return 0;
}
