#include<bits/stdc++.h>
using namespace std;
long long n,m,num[200005];
bool a[200005][35];
long long two[35];
int cmp(int x,int y)
{
	return x > y;
}
long long pown(int x)
{
	long long y = 1;
	for(int i = 1;i <= x;i++)
		y*=2;
	return y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
	sort(num+1,num+1+n,cmp);
	for(int i = 0;i < 32;i++)
		two[i] = pown(i);
	for(int i = 1;i <= n;i++)
	{	
		for(int j = 1;j <= 31;j++)
		{
			if(num[i] < two[31-j])
				a[i][j] = 0;
			else
			{
				a[i][j] = 1;
				num[i]-=two[31-j];
			}
		}
	}
	int n_cnt = n;
	long long ans = 0;
	for(int j = 1;j <= 31;j++)
	{
		int cnt = 0;
		for(int i = 1;i <= n_cnt;i++)
		{
			if(a[i][j] == 1)
				cnt++;
		}
		if(cnt >= m)
		{
			ans+=two[31-j];
			n_cnt = cnt;
		}
	}
	cout << ans;
	return 0;
}
