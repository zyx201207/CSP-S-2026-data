#include <iostream>

std::string c1, s1, c2, s2;
bool ans1, ans2, ans3, ans4;

int main() {
	std::freopen("travel.in", "r", stdin);
	std::freopen("travel.out", "w", stdout);
	std::cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans1 = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			ans2 = 1;
			char c1 = s1[2], c2 = s2[2];
			if (('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C') || ('D' <= c1 && c1 <= 'F' && 'D' <= c2 && c2 <= 'F')) {
				ans3 = 1;
				char c3 = std::min(c1, c2), c4 = std::max(c1, c2);
				if ((c3 == 'A' && c4 == 'B') || (c3 == 'B' && c4 == 'C') || (c3 == 'D' && c4 == 'F'))
					ans4 = 1;
				else ans4 = 0;
			} else ans3 = ans4 = 0;
		} else ans2 = ans3 = ans4 = 0;
	} else ans1 = ans2 = ans3 = ans4 = 0;
	std::cout << ans1 << ans2 << ans3 << ans4 << '\n';
	return 0;
}