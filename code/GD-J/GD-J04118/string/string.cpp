#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
long long n , idx1 = 1 , ans , idx2 , sum1 , idx3 = 0;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	scanf("%lld" , &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld%s" , &a[i] , &c[i]);
		sum1 += a[i];
	}
	idx2 = n;
	while(idx3 < (sum1 / 2) && idx1 < idx2)
	{
//		cout << idx1 << " " << idx2 << " " << ans << endl;
		if(c[idx1] != c[idx2])
		{
			ans += min(a[idx1] , a[idx2]);
			if(a[idx1] > a[idx2])
			{
				a[idx1] -= a[idx2];
				idx2--;
			}
			else if(a[idx1] == a[idx2])
			{
				idx1++ , idx2--;
			}
			else
			{
				a[idx2] -= a[idx1];
				idx1++;
			}
		}
		else
		{
			if(a[idx1] > a[idx2])
			{
				a[idx1] -= a[idx2];
				idx2--;
			}
			else if(a[idx1] == a[idx2]){idx1++ , idx2--;} 
			else
			{
				a[idx2] -= a[idx1];
				idx1++; 
			}
		}
		idx3 += min(a[idx1] , a[idx2]);
//		cout << idx1 << " " << idx2 << " " << idx3 << " " << ans << endl;
	}
	printf("%lld" , ans);
	return 0;
}
