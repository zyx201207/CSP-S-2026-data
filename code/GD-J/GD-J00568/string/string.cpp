#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a;
	char c;
}arr[200005];
int n;
long long i, j, ans = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	i = 1;	j = n;
	for(int x = 1;x <= n;x++)
	{
		cin >> arr[x].a >> arr[x].c;
	}
	while(i <= j)
	{
		if(arr[i].a < arr[j].a)
		{
			if(arr[i].c != arr[j].c)
			{
				ans += arr[i].a;
				arr[j].a -= arr[i].a;
				i++;
			}
			else
			{
				arr[j].a -= arr[i].a;
				i++;
			}
		}
		else if(arr[j].a < arr[i].a)
		{
			if(arr[i].c != arr[j].c)
			{
				ans += arr[j].a;
				arr[i].a -= arr[j].a;
				j--;
			}
			else
			{
				arr[i].a -= arr[j].a;
				j--;
			}
		}
		else
		{
			if(arr[i].c != arr[j].c)
			{
				ans += arr[i].a;
				i++;
				j--;
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
} 
