#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	string f;
	cin >> n;
	int sum = 0;
	string a;
	for (int i = 1;i <= n;i++)
	{
		int d;
		cin >> d;
		string c;
		cin >> c;
		for (int i = 1;i <= d;i++)
		{
			a = a + c;
			 
		}
	}
		
	for (int i = a.size() - 1;i >= 0;i--)
	{
		f[i] = a[a.size() - i - 1];
	}
	for (double j = 0;j < a.size();j++)
	{
		if (a[j] != f[j])
		{
			sum++;
		}
	}
	
	cout << sum / 2;
	return 0;
}
