#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

int a, b;
int sha, shb;
char sla, slb;
std::string sa, sb;

int main() 
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::cin >> a >> sa >> b >> sb;
	sha = sa[0] * 10 + sa[1];
	shb = sb[0] * 10 + sb[1];
	sla = sa[2], slb = sb[2];
	bool ans1, ans2, ans3, ans4;
	ans1 = (a == b);
	ans2 = (sha == shb && ans1 ? 1 : 0);
	ans3 = ans2 && (sla <= 'C' && slb <= 'C' || sla > 'C' && slb > 'C');
	ans4 = ans3 && abs(sla - slb) < 2;
	std::cout << ans1 << ans2 << ans3 << ans4;
}

