#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,ans;
int a[maxn];
int b[maxn][35];
int cmp(int x,int y) {return x > y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n,cmp);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;(1 << j) <= a[i];j++)
		{
			if(a[i] & (1 << j)) b[i][j] = 1;
			else b[i][j] = 0;
		}
	}
	/*for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j <= 30;j++)
		{
			cout << b[i][j];
		}
		cout << endl;
	}*/
	for(int j = 30;j >= 0;j--)
	{
		for(int i = 1;i <= n;i++)
		{
			if(b[i][j] == 0)
			{
				if(i - 1 >= m) n = i - 1;
				break;
			}
		}
	}
	//cout << "n为：" << n << "，m为：" << m << endl;
	cout << a[m];
    return 0;
}
