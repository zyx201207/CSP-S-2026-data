/*
1 ≤ n ≤ 2 × 10^5；
对于所有 i (1 ≤ i ≤ n)，均有 1 ≤ ai ≤ 109，且 ci 为小写英文字母。
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define wmin(a,b) ((a)<(b) ? (a) : (b))

const int N=2e5;
int a[N+105];
char c[N+105];

signed main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int sum=0;
	for (int i0=1,i1=n; i0<i1;)
	{
//		cout << i0 << " " << i1 << " " << "---\n";
		int num=wmin(a[i0],a[i1]);
//		cout << a[i0] << " " << a[i1] << " " << num << "--\n";
		if (c[i0]!=c[i1])
		{
			sum+=num;
		}
		a[i0]-=num; a[i1]-=num;
//		if (a[i0]<=0) i0++; //MPW
//		if (a[i1]<=0) i1--; //MPW

//		cout << a[i0] << " " << a[i1] << " " << num << "----\n";
		if (a[i0]==0) i0++;
		if (a[i1]==0) i1--;
	}
	cout << sum;
	return 0;
}

/*
3
2 a
2 b
1 c

2
*/

/*
2
2 a
3 a

0
*/

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000
*/
