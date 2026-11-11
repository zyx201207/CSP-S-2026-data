#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll num;
	char s;
}a[200005];
ll ans,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i].num>>a[i].s;
	string st = " ";
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=a[i].num;j++) 
		{
			st += a[i].s;
			cnt++;
		}
	}
	for(ll i = 1;i<cnt-i+1;i++)
	{
		if(st[i] != st[cnt-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

