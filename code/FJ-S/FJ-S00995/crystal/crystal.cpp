#include<bits/stdc++.h>//回来自己造样例！！
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,final=0;
int a[MAXN];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,k=m,ans=1;
	for(int i=1;i<=n-1;i++)
	{
		if(k-(i-l+1)*(a[i+1]-a[i])<0)
		{
			k=k-(i-l+1)*(a[i+1]-a[i]);
			final=max(final,ans);
			while(k<0)
			{
				k=k+(a[i+1]-a[l]);
				l++;
				ans--;
			}
			ans++;
//			l--;
			ans=max(1ll,ans);
			
		}
		else
		{
			k=k-(i-l+1)*(a[i+1]-a[i]);
			ans++;
			final=max(final,ans);
		}
	}
	cout<<final;
	return 0;
}
