#include <iostream>
#include <cstdio>

struct stringNode {
	long long int a, rgst, rged;
	char c;
} str[200010];

long long int minNum (long long int a, long long int b) {
	if (a < b) return a;
	return b;
}

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	int n;
	std::cin >> n;
	
	str[0].rged = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> str[i].a >> str[i].c;
		str[i].rgst = str[i-1].rged + 1;
		str[i].rged = str[i-1].rged + str[i].a;
	}
	
	long long int	left = 1, right = str[n].rged, checkValue = 0, lRgeP = 1, rRgeP = n, dftValue, wtRound;
	char			leftc, rightc;
	while (left <= right) {
		while (!(left >= str[lRgeP].rgst and left <= str[lRgeP].rged)) {
			lRgeP++;
		} leftc = str[lRgeP].c;

		while (!(right >= str[rRgeP].rgst and right <= str[rRgeP].rged)) {
			rRgeP--;
		} rightc = str[rRgeP].c;
		
		dftValue = 0;
		if (leftc != rightc) {
			checkValue++;
			dftValue = 1;
		}
		
		if (wtRound <= 0) {
			long long int dstLeft = str[lRgeP].rged - left;
			long long int dstRight = right - str[rRgeP].rgst;
			long long int goDst = minNum (dstLeft, dstRight);
			left += goDst; right -= goDst;
			if (dftValue == 1) checkValue += goDst;
			wtRound = 5;
		}
		
		left++;
		right--;
		wtRound--;
	}
	
	printf ("%lld", checkValue);
	return 0;
}
