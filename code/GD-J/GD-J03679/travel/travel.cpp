#include <bits/stdc++.h>

int main() {
	freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
	int c1, c2, r1, r2;
	std::string str1, str2;
	
	std::cin >> c1 >> str1 >> c2 >> str2;
	if (c1 == c2) {
		std::cout << 1;
		std::string s1, s2;
		s1 = str1[0] + str1[1], s2 = str2[0] + str2[1];
		if (s1 == s2) {
			std::cout << 1;
			char c1 = str1[2], c2 = str2[2];
			if (c1 > c2) std::swap(c1, c2);
			if (c1 >= 'D' || c2 <= 'C') {
				std::cout << 1;
				if (c1 >= 'D' || (c2 <= 'C' && !(c1 == 'A' && c2 == 'C'))) std::cout << 1;
				else std::cout << "0";
			} else std::cout << "00"; 
		} else std::cout << "000";
	} else std::cout << "0000";
	
	return 0;
}
