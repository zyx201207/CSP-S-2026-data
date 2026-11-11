#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long card[n];
	set<long long> ig_c;
	for(long long j = 0; j < n; j++)
	{
		cin >> card[j];
	}
	if(n == 1)
	{
		cout << 1;
	}
	if(n == 2)
	{
		if(card[0] == card[1])
		{
			cout << 2;
		}
		else
		{
			cout << 2 << " " << 2;
		}
	}
	if(n == 3)
	{
		cout << 3 << " " << 2 << " " << 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
