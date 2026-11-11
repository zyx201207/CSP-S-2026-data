#include <bits/stdc++.h>

using namespace std;
long long vis[500005];
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long ans = 0;
	long long n,m;
	long long len = 1;

	cin >> n >> m;

	for(long long i = 1;i <= n;i ++)
	{
		cin >> a[i];
		//cout << a[i]<< " ";
	}
	sort(a+1,a+n);
	long long mid = a[(n+1)/2];
	ans ++;
	//cout << mid << " ";
	for(long long i = 1;i <= n;i++)
	{
		if(i == (n+1)/2)
			continue;
		if(a[i] == mid)
		{
			ans ++;
		}	
		if(a[i] < mid)
		{
//			cout << a[i]<< " ";
			vis[len++] = a[i];
			ans ++;
		}	
	}
//	cout << ans << " ";
	long long need = 0;
	//cout << len << " ";
	for(long long i = len-1;i >= 1;i --)
	{
		//cout << vis[i] << " ";
		need += mid - vis[i];
//		cout << need << "    ";
		if(need > m)
		{
		//	cout <<"       "<< need<< "    ";
			ans --;
			break;
		}
 	}
 	cout << ans;
	return 0; 
}