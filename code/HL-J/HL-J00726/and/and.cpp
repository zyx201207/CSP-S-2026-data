#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int n,a[N],m;
int f[N],ans = -1e18;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	for(int i = 1;i <= n;i++)
	{
		f[1] = a[i];
		for(int j = 2;j <= m;j++)
		{
			f[j] = -1e18;
		}
		for(int j = 2;j <= m;j++){
			f[j] = max(f[j-1],f[j] & a[i]);
		}
	}
	
	cout << f[m] << '\n';

	return 0;
}
