#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mn = LLONG_MAX,x[200005],ans;
char c[200005];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>c[i],mn = min(mn,x[i]);
	for(int i=1;i<=n;i++) x[i] -= mn - 1;
	for(int i=1;i<=n;i++) while(x[i]--) s += c[i];
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i] != s[j]) ans++;
	}
	cout<<ans * mn<<"\n";
	return 0;
}