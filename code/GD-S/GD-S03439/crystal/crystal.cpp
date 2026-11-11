#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],s[N];
int n,m;
bool check(int x,int y)
{
	int t=a[x]*y-s[x]+s[x-y];
	return t<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(i,mid))l=mid;
			else r=mid-1;
		}
		maxn=max(maxn,l);
	}
	cout<<maxn<<endl;
	return 0;
}
