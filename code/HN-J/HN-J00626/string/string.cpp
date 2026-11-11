#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char ch[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>ch[i];
	int l=1,r=n;
	while(l<r)
	{
		if(ch[l]==ch[r])
		{
			int minn=min(a[l],a[r]);
			a[l]-=minn,a[r]-=minn;
			if(!a[l])l++;
			if(!a[r])r--; 
		} 
		else
		{
			int minn=min(a[l],a[r]);
			ans+=minn;
			a[l]-=minn,a[r]-=minn;
			if(!a[l])l++;
			if(!a[r])r--; 
		}
	}
	cout<<ans;
	return 0;
}

