#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
const int N = 5e5 + 5;
ll a[N] , sum[N];
struct TREE
{
	ll tree[4 * N];
	void set()
	{
		for(int i = 0;i <= 4 * N - 1;i++)tree[i] = -1e18;
	}
	void build(int l , int r , int p)
	{
	//	cout<<l<<" "<<r<<endl;
		if(l == r)
		{
			tree[p] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l , mid , 2 * p) , build(mid + 1 , r , 2 * p + 1);
		tree[p] = max(tree[2 * p] , tree[2 * p + 1]);
	}	
	ll get(int l , int r  , int s , int t , int p)
	{
	//	cout<<l<<" "<<r<<endl;
		if(s <= l && r <= t)
			return tree[p];
		ll re = -1e18;
		int mid = (l + r) >> 1;
	//	cout<<l<<" "<<mid<<" "<<r<<endl; 
		if(mid >= s)re = get(l , mid , s , t , 2 * p);
		if(mid < t)re = max(re , get(mid + 1 , r , s , t , 2 * p + 1));
		return re;
	}
}S;
int main()
{
	freopen("crystal.in" , "r" , stdin) , freopen("crystal.out" , "w" , stdout);
//	cout<<fixed<<setprecision(10)<<5e5 * log2(5e5)<<endl;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1;i <= n;i++)sum[i] = sum[i - 1] + a[i];
	S.set() , S.build(1 , n , 1);
	int lst = 1;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		//cout<<lst<<" "<<i<<endl;
		while(lst < i && S.get(1 , n , lst , i , 1) * (ll)(i - lst + 1) - (sum[i] - sum[lst - 1]) > m)lst++;
		ans = max(ans , i - lst + 1);
	}
	cout<<ans;
	return 0;
} 
