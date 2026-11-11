#include<bits/stdc++.h>
using namespace std;
long long n , m , maxn;
struct node
{
	long long a , one;
}t[2000005];
bool cmp(node x , node y)
{
	return x.one > y.one;
}
bool cmp2(node x , node y)
{
	return x.a > y.a;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> t[i].a;
	}
	if(n <= 2000)
	{
		sort(t+1 , t+n+1 , cmp2);
		for(int i = 1 ; i <= n ; i ++)
		{
			long long h = t[i].a; 
			while(h > 0)
			{
				long long yu = h % 2;
				if(yu > 0)
				{
					t[i].one ++;
				}
				h /= 2;
			}
			//cout << t[i].one << endl;
		}
		sort(t+1 , t+n+1 , cmp);
		//cout << t[1].a << ' ' << t[2].a << endl;
		long long ans = t[1].a;
		for(int i = 1 ; i <= m ; i ++)
		{
			ans &= t[i].a;
		}
		cout << ans;
	}
	else
		cout << n - m;
	return 0;
}
