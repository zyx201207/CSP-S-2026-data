#include <bits/stdc++.h>
using namespace std;

string a,b,c,d;

inline int f1(char c) {
	if(c == 'A' || c == 'B' || c == 'C') return 1;
	else return 0;
}

inline bool f2(char x,char y) {
	int n = f1(x),m = f1(x);
	if(n == m) {
		if(n == 1) {
			if(x + 1 == y || x - 1 == y) return true;
			else return false;
		}
		if(n == 0) {
			if(x == 'F' && y == 'D') return true;
			if(x == 'D' && y == 'F') return true;
			else return false;
		}
	}
	else return false;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	bool flag1 =  false,flag2 = false,flag3 = false;
	if(a == c) printf("1"),flag1 = true;
	else printf("0");
	
	if(flag1 && b[0] == d[0] && b[1] == d[1]) printf("1"),flag2 = true;
	else printf("0");
	
	if(flag1 && flag2 && f1(b[2]) == f1(d[2])) printf("1"),flag3 = true;
	else printf("0");
	
	if(flag1 && flag2 && flag3 && f2(b[2],d[2])) {
		printf("1");
	}
	else printf("0");
	return 0;
} 
