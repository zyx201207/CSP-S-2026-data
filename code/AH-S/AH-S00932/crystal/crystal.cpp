#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,ma=0,s=0,l,c=0;
	cin>>n>>m;
	l=n-1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(i!=n)
			s-=c*(a[i+1]-a[i]),c--;
		while(s+(a[i]-a[l])<=m&&l>=1)
			s+=a[i]-a[l],l--,c++;
		ma=max(ma,c);
	}
	cout<<ma+1;
	return 0;
}

