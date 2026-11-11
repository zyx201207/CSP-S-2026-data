#include<bits/stdc++.h>
using namespace std;

int n, a1;
long long sum;
char c1;
string m; 
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a1 >> c1;
		for(int j=0; j<a1; j++)
		{
			m += c1;
		}
	}
	for(int i=0; i<m.size() / 2; i++)
	{
		if(m[i] != m[m.size() - i - 1])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
