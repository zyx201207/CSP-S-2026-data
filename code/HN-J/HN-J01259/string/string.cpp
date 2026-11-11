#include <bits/stdc++.h>
using namespace std;

string zm[200005];
long long num[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,zh;
	long long ans = 0;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> num[i];
		cin >> zm[i];
		zh+=num[i];
	}
	
	for(int i = 0;i < n/2;i++)
	{
		if(zm[i] == zm[n-i-1])
		{
			if(num[i] < num[n-i-1])
			{
				num[n-i-1]-=num[i];
				n++; 
			}
			else if(num[i] > num[n-i-1])
			{
				num[i]-=num[n-i-1];
				i--;
				n--;
			}
		}
		else
		{
			if(num[i] < num[n-i-1])
			{
				ans+=num[n-i-1]-num[i];
				num[n-i-1]-=num[i];
				n++;
			}
			else if(num[i] > num[n-i-1])
			{
				ans+=num[i]-num[n-i-1];
				num[i]-=num[n-i-1];
				i--;
				n--;
			}
			else
			{
				ans+=num[i];
			}
		}
	}
	
	cout << ans;
	
	
	return 0;
}
