#include<bits/stdc++.h> 
using namespace std;
int n,m,a[100005],num = -1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i =1 ; i <= n; i++)
	{
		for(int j = i; j <= m; j++)
		{
			if((a[j] & a[j + 1])> num)
			{
				num = (a[j] & a[j + 1]);
			}
		}
	}
	cout << num;
	return 0;
}
