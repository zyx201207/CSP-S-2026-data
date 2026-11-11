#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
template<class T>bool ckmax(T &x, const T y) {return (x < y ? x = y, 1 : 0);}
template<class T>bool ckmin(T &x, const T y) {return (x > y ? x = y, 1 : 0);}
inline int read() {
	int f = 1, w = 0, ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) w = w * 10 + ch - '0';
	return f * w;
}
int c1, t1, c2, t2;
char s1[10], s2[10];
string ans;
int main() {
//	freopen("travel5.in", "r", stdin);
//	freopen("travel5.out", "w", stdout);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	c1 = read();
	scanf("%s", s1);
	c2 = read();
	scanf("%s", s2);
	if (c1 != c2) {
		printf("0000");
		return 0;
	}
	t1 = (s1[0] - '0') * 10 + s1[1] - '0';
	t2 = (s2[0] - '0') * 10 + s2[1] - '0';
	if (t1 != t2) {
		printf("1000");
		return 0;
	}
	if (s1[2] == 'F') s1[2] = 'E';
	if (s2[2] == 'F') s2[2] = 'E';
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
		if (s1[2] == s2[2] - 1 || s1[2] == s2[2] + 1) {
			printf("1111");
			return 0;
		} else {
			printf("1110");
			return 0;
		}
	} else {
		printf("1100");
		return 0;
	}
	return 0;
}
