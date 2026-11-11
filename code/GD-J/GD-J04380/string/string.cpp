#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,ans;
int a[N];
char c[N];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		bool flat = (c[l] != c[r]);
		if(a[l] == a[r])
		{
			ans+=a[l]*flat;
			l++,r--;
		}
		else if(a[l] < a[r])
		{
			a[r] -= a[l];
			ans += a[l]*flat;
			l++;
		}
		else if(a[r] < a[l])
		{
			a[l] -= a[r];
			ans += a[r]*flat;
			r--;
		}
	}
	cout<<ans;
	
	return 0;
}
