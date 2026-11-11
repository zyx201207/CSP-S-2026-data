#include<bits/stdc++.h>
using namespace std;
#define N 200005
long long arr[N];
char c[N];
void f(long long cnt, int m, int x)
{
	if(m == x) return ; 
	if(c[m] != c[x])
		{
			cnt += min(arr[m], arr[x]);
			arr[m] -= min(arr[m], arr[x]);
			arr[x] -= min(arr[m], arr[x]);
			if(arr[m] != 0)
			{
				return f(cnt, m, x - 1);
			}else if(arr[x] != 0)
			{
				return f(cnt, m + 1, x);
			}else if(arr[m] == 0 && arr[x] == 0)
			{
				return f(cnt, m + 1, x - 1);
			}
		}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long cnt = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i];
		cin >> c[i];
	}
	f(cnt, 0, n - 1);
	cout << cnt <<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
