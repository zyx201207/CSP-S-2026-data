#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n;
int a[MAXN];
char c;
string x;

long long huiwen(string a)
{
	long long sum = 0;
	for (long long  i = 0, j = a.size() - 1; i < j; i++, j--)
	{
		if (a[i] != a[j])
		{
			a[j] = a[i];
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		cin >> c;
		for (int j = 0; j < a[i]; j++)
		{
			x += c;
		}
	}
	printf("%lld", huiwen(x));
	return 0;
}
