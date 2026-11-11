#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, len = 0, cnt = 0;
	cin >> n;
	string sum = " ";
	for (int i = 1; i <= n; i++){
		int num; string s;
		cin >> num >> s;
		len += num;
		for (int j = 1; j <= num; j++) sum += s;
	}
	for (int i = 1; i <= len / 2; i++){
		if (sum[i] != sum[len - i + 1]) cnt++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
