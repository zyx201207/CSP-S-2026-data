#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=2e5+10;
const int Maxc=35;
bitset<Maxn> mask[Maxc];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		for(int j=0;x;j++,x>>=1)
		{
			mask[j][i]=x&1;
		}
	}
	// for(int i=0;i<30;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout << mask[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	bitset<Maxn> cur;
	for(int i=0;i<Maxn;i++)
	{
		cur[i]=1;
	}
	ll ans=0;
	for(int i=29;i>=0;i--)
	{
		bitset<Maxn> ncur=cur&mask[i];
		if(ncur.count()>=m)
		{
			cur=ncur;
			ans+=(1LL<<i);
		}
	}
	cout << ans;
	return 0;
}