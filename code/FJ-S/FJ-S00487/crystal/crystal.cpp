#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n; long long m;
long long a[N],sum[N];
int ans = 0;

ifstream fin("crystal.in",ios_base::in);
ofstream fout("crystal.out",ios_base::out);
int main()
{
	ios::sync_with_stdio(0); fin.tie(0); fout.tie(0);
	fin >> n >> m;
	for(int i = 1; i <= n; i++)	fin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		while(a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) > m)
			j++;
		ans = max(ans,i - j + 1);
	}
	fout << ans << '\n';
	return 0;
}
/*
in1:
5 5
1 2 4 8 9
out1:
3
in2:
5 8
-3 -1 2 2 7
out2:
4
*/
