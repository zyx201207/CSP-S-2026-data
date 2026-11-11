#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	char ch;
	int sum;
}a[220000];
int n;
int L;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].sum>>a[i].ch;
		L+=a[i].sum;
	}
	int l=1,r=n,s=0;
	while (s<=L/2)
	{
		int now=a[l].sum;
		if (s+now>L/2)
			now=L/2-s;
		while (now!=0)
		{
			int t=min(a[r].sum,now);
			now-=t;
			a[r].sum-=t;
			if (a[l].ch!=a[r].ch)
				ans+=t;
			if (a[r].sum==0)
				r--;
		}
		s+=a[l].sum;
		l++;
	} 
	cout<<ans;
	return 0;
}
