#include <iostream>
#include <stdio.h>
#include <algorithm>

int n, m, ans;
int s[(int)2e5 + 10];

bool cmp(int a, int b){
	return a > b;
}

int main() 
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	std::cin >> n >> m;
	for(int i = 0;i < n;i++) {
		std::cin >> s[i];
	}
	std::sort(s, s + n, cmp);
	ans = ~0; 
	for(int i = 0, j = 1;j <= m && i < n; i++) {
		if((ans & s[i]) != 0){
			ans &= s[i];
			j++;
		}
		else {
			ans = s[i];
			j = 2;
		}
	}
	std::cout << ans;
}

