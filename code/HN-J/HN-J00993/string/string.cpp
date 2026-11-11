#include <iostream>
#include <stdio.h>
#include <algorithm>

#define int long long

struct Node
{
	long long len;
	char c;
}s[(int)2e5 + 10];


int n, now = 1, len, ans;
int num;
char c;

signed main() 
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::cin >> n;
	while(n--) {
		std::cin >> s[now].len >> s[now].c;
		if(s[now].c == s[now - 1].c) {
			s[now- 1].len += s[now].len;
			continue;
		}	
		now++;
	}
	int laststart = now - 1;
	//std::cout << now << '\n';
	for(int i = 1;i <= laststart;i++) {
		int nowlen = s[i].len;
		for(int j = laststart;j >= 1 && nowlen;j--) {
			//std::cout << i << ' ' << j << ' ' <<  std::min(nowlen, s[i].len) * (s[i].c != s[j].c) << '\n';
			ans += std::min(nowlen, s[j].len) * (s[i].c != s[j].c);
			if(s[j].len > nowlen) {
				s[j].len -= nowlen;
				nowlen = 0;
				break;
			}
			else {
				nowlen -= s[j].len;
				laststart--;
		 	}
		}
	}
	std::cout << ans;
}

