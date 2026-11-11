#include <iostream>
#include <cstdio>
using namespace std;
int b[200010];
char c[200010][2]; 
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	long long sum(0);
	cin >> n;
	for(int i(1); i <= n; i++)
	{
		cin >> b[i] >> c[i];
	}
	for(int i(1), j(n); i < j; )
	{
		if(c[i][0] != c[j][0])
		{
			if(b[i] > b[j])
			{
				sum += b[j];
				b[i] -= b[j];
				j--;
			}
			else if(b[j] > b[i])
			{
				sum += b[i];
				b[j] -= b[i];
				i++;
			}
			else
			{
				sum += b[i];
				i++;
				j--;
			}
		}
		else
		{
			if(b[i] > b[j])
			{
				j--;
				b[i] -= b[j];
			}
			else if(b[j] > b[i])
			{
				i++;
				b[j] -= b[i];
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	cout << sum;
	return 0;
} 
