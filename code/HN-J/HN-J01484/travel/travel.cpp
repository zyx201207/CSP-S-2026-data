#include <bits/stdc++.h>

using ll = long long;
#define f first
#define s second
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

std::string s1, s2, c1, c2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) std::cout << '1';
	else return std::cout << "0000\n", 0;
	if (s1.substr(0, 2) == s2.substr(0, 2)) std::cout << '1';
	else return std::cout << "000\n", 0;
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) std::cout << '1';
	else return std::cout << "00\n", 0;
	char ch1 = s1[2], ch2 = s2[2];
	if (ch1 > ch2) std::swap(ch1, ch2);
	if (ch2 <= 'C') if (ch1 + 1 == ch2) std::cout << '1';
	else return std::cout << "0\n", 0;
	else if (ch1 <= 'C') return std::cout << "0\n", 0;
	else return std::cout << "1\n", 0;
	return 0;
}
