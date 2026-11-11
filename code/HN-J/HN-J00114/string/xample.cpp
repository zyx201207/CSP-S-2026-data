#include <bits/stdc++.h>
using namespace std;
int n = 2e5;
char s[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main()	{
	freopen("string.txt", "w", stdout);
	cout << n << '\n';
	int i = 0;
	while (n--) {
		cout << (int)1e9 - i * 17 << ' ' << s[(i += 1) % 26] << '\n';
	}
	return 0;
}
