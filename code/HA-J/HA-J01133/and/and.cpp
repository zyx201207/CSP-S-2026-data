#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int num[n];
	for(int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	if(n % 2 == 0)
	{
		cout << num[n / 2 + 1 - 1];
	}
	else
	{
		cout << num[(n - 1) / 2 - 1];
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
