#intclude <bits/stdc++.h>
using namespace std;
int n, m;
int a[2000010];
bool cmp(int a, int b)
{
	return a&b > b&a;
} 

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << max;
	return 0;
} 
