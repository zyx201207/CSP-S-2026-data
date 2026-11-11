#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[100000];
	string b[10000];
	string s = {0};
	int sum = 0;
	int ans = 0;

	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		cin >> b[i];
		for(int j = 0;j < a[i];j++)
		{
			s += b[i];
			sum++;
		}
	}
	if(sum % 2 == 1)
	{
		for(int i = 0;i < sum/2+1;i++)
		{
			if(s[sum/2 - i] != s[sum/2 + i])
			{
				ans++;
			}
		}
	}
	else
	{
		for(int i = 0;i < sum/2+1;i++)
		{
			if(s[sum/2 + i] != s[sum/2 - 1 - i])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
