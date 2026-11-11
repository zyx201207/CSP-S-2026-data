#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=4e5+5;
int n,m,a[mx];
int ans;
int now;
bool vis[mx];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=31;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(((a[j]>>i)&1)==1)
			{
				cnt++;
				swap(a[cnt],a[j]);
			}
		}
		if(cnt>=m)
		{
			n=cnt;
			ans|=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
/*

3ºÅÑùÀýhack 

*/

