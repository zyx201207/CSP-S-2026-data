#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N], sum, ans;
char c[N];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
	*/
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	sum /= 2;
	int cnt = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(cnt < sum && cnt + a[i] > sum)
		{
			for(int j = n;j >= i + 1;j --)
			{
				a[j + 1] = a[j]; 
				c[j + 1] = c[j];
			}
			a[i + 1] = cnt + a[i] - sum;
			c[i + 1] = c[i];
			a[i] = sum - cnt;
			n ++;
			break;
		}
		cnt += a[i];
	}
	int num1 = a[1], num2 = a[n];
	for(int i = 1, j = n;i < j;)//双指针 
	{
		//num1,num2保证左右移动的距离相等,保持回文 
		while(c[i] == c[j] && i < j)
		{
			if(num1 > num2)
			{
				sum -= num2;
				num1 -= num2;
				j --;
				num2 = a[j];
			}
			else if(num1 == num2)
			{
				sum -= num1;
				i ++,j --;
				num1 = a[i], num2 = a[j];
			}
			else if(num2 > num1)
			{
				sum -= num1;
				i ++;
				num1 = a[i];
			 } 
		}
		while(c[i] != c[j] && i < j)
		{
			if(num1 > num2)
			{
				num1 -= num2;
				j --;
				num2 = a[j];
			}
			else if(num1 == num2)
			{
				i ++, j --;
				num1 = a[i], num2 = a[j];
			}
			else if(num2 > num1)
			{
				num2 -= num1;
				i ++;
				num1 = a[i];
			}
		}
	}
	cout << sum <<'\n';
	return 0;
}

