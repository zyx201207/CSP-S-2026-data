#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],b[200010],c[200010],cnt,t,ans;
bool f;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0); 
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	t=n;
	//a >> x & 1
	for (int x=35;x>=0;x--)
	{
		cnt=0;
		for (int i=1;i<=t;i++)
		{
			if ((b[i]>>x&1)==1) c[++cnt]=b[i];
		}
		ans<<=1;
		if (cnt>=m)
		{
			for (int i=1;i<=cnt;i++) b[i]=c[i];
			t=cnt;
			ans|=1;
		}
	}
	cout<<ans;
	return 0;
}
