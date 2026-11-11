#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];m--;
	for(int i=2;i<=n;i++)
	{
		if(m-1>=0)
		{
			ans=ans&a[i];
			m--;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
(12

5 3
31 3 1 15 7
(7
*/
