#include<bits/stdc++.h>
using namespace std;
#define ll long long
//1 <= m <= n <= 2e5
//0 <= a[i] < (1<<30)
const int N = 2e5 + 10;
int n,m;ll ans;//ans < (1<<30)
int a[N];
bool vis[N];ll cnt;//cnt<=n
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	ans = 0;
	memset(vis,0,sizeof(vis));
	for(ll j = 29,i; j >= 0; j--)
	{
		i = (1 << j);
		cnt = 0;
		for(int k = 1; k <= n; k++)
		{
			if(!vis[k] && (a[k] & i)) cnt++;
		}
		if(cnt < m) continue;
		ans |= i;
		for(int k = 1; k <= n; k++)
		{
			if((a[k] & i) == 0)
			{
				vis[k] = 1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

