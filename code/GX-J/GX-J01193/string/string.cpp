#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	long long int num[200005] = {0};
	char str[200005] = {0};
	
	for(int i = 0;i<n;i++)
	{
		cin >> num[i] >> str[i];
	}
	
	long long int ans = 0;
	int head = 0;
	int tail = n-1;
	while(head <= tail)
	{
		if(str[head] != str[tail])
		{
			if(num[head] > num[tail])
			{
				ans += num[tail];
				num[head] -= num[tail];
				tail --;
			}
			else if(num[head] < num[tail])
			{
				ans += num[head];
				num[tail] -= num[head];
				head ++;
			}
			else
			{
				ans += num[head];
				tail --;
				head ++;
			}
		}
		else
		{
			if(num[head] > num[tail])
			{
				num[head] -= num[tail];
				tail --;
			}
			else if(num[head] < num[tail])
			{
				num[tail] -= num[head];
				head ++;
			}
			else
			{
				tail --;
				head ++;
			}
		}
	}
	cout << ans;
	
	return 0;
}
