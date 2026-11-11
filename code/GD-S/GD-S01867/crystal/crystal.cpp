#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if(n <= 5000)
	{
		int ret = 0;
		for(int i = 1;i <= n;i++)
		{
			int dfn = 0;
			long long cnt = 0;
			for(int j = i;j <= n;j++)
			{
				cnt += a[j];
				dfn++;
				if(a[j] * dfn - cnt > m)break;
				ret = max(ret,j - i + 1);
			}
		}	
		cout << ret;
		return 0;
	} 
	int l = 1;
	int ret = 0;
	long long d = 0,sum = 0,sum2 = 0;
	for(int r = 1;r <= n;r++)
	{
		sum += a[r];
		d = a[r] * (r - l + 1) - sum;
		while(l <= r && d > m)
		{
			sum -= a[l];
			l++;
			d = a[r] * (r - l + 1) - sum;
		}
		ret = max(ret,r - l + 1);
	}
	cout << ret;
	return 0;
} 
