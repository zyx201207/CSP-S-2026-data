#include<bits/stdc++.h>
using namespace std;
#define rig register int
int n,m,a[200005];
inline bool pd(const int &x)
{
	rig s=1;
	for(rig i=x,j=i+1;j<=n;j++)
		if((a[i]&a[j]&a[x])==a[x])
			s++,i=j;
	return s>=m;
}
main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(rig i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(rig i=n;i;i--)
		if(pd(i))
		{
			cout<<a[i];
			return 0;
		}
}
