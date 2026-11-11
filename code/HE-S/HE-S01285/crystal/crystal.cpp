#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int n,m;
int a[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;++i) cin >>a[i];
	sort(a+1,a+n+1);
	int sum=0,base=a[n],pos=n,maxn=0;
	for(int i=n;i>=1;--i)
	{
		if(sum+abs(base-a[i])<=m) sum+=abs(base-a[i]);
		else
		{
			maxn=max(maxn,pos-i);
			sum=sum-(pos-i)*(a[pos]-a[pos-1]);
			pos--;
			base=a[pos];
			i++;
		}
	}
	maxn=max(maxn,pos);
	cout <<maxn<<'\n';
}
