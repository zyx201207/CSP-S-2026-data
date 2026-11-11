#include <bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
const int N = 2e5+10;
int n,x[N],w,t,b[250],z,q;
char a[N],k;
bool f = 0,l = 0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	q = n/2;
	for (int i = 1;i <= n;i++)
	{
		cin >> x[i] >> a[i];
		b[a[i]] += x[i];
		t += x[i];
		if (b[a[i]] >= z)
		{
			z = b[a[i]];
			k = a[i];
		}
	}
	z = 0;
	for (int i = 1;i <= q;i++)
	{
//		if (l == 0)
//		{
//			z += x[i];
//			if (z >= t/2)
//			{
//				l = 1;
//				f = 1;
//				if (a[i] == k)
//				{
//					f = 0;
//				}
//			}
//		}
		if (a[i] != k)
		{
			if (a[n-i+1] == a[i])
			{
				w += abs(x[i]-x[n-i+1]);
//				cout << w << " ";
			}
			else
			{
				w += x[i];
			}
		}
	}
//	if (t%2 == 1)
//	{
//		w -= f;
//	}
	cout << w;
	return 0;
}
/*
7
5 a
3 b
2 c
1 d
1 c
2 b
5 a
*/
