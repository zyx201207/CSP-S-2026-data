#include<iostream>
#include<algorithm>
using namespace std;

#define int long long 

const int N = 5e5 + 5;
int a[N],pre[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		pre[i] = pre[i-1] + a[i];
	}
	int maxn = -2e9;
	for(int i = 1;i<=n;i++)
	{
		int l = 1,r = i;
		while(l <= r)
		{
			int mid = (l+r)/2;
			//
			if(1ll * (i - mid) * a[i] - (pre[i-1] - pre[mid - 1]) <= m)r = mid - 1;
			else l = mid + 1;
		}
		//l?
		maxn = max(maxn, i - (l+r)/2);
		//cout << i << ' ' << l << ' ' << r << ' ' << (l+r)/2 << endl << endl;
		
		
		//優化思路：1~i二分查找 
		/* 
		int tmp = m,ans = 1;
		for(int j = i-1;j>=1;j--)
		{
			if(tmp - (a[i] - a[j]) < 0)break;
			tmp -= a[i] - a[j];
			ans++;
			//cout << i << "->" << j << endl;
		}
		*/
		
	}
	cout << maxn;
	return 0;
 } 
 //rp++
 //rp++
 //求求你了1=
 //csp我愛你
 //100+40+32+0=172 
