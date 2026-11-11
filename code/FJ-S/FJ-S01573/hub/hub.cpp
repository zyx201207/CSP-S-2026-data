#include<bits/stdc++.h>
using namespace std;
uint8_t buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 =(p1 = buf) + fread(buf, 1, 1 << 20, stdin)), *p1++)
int readint() {
	int k = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) {
		if (c == '-')
			f = -1;
	}
	for (; isdigit(c); c = gc()) {
		k = k * 10 + (c - '0');
	}
	return f * k;
}

long long readll() {
	long long k = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) {
		if (c == '-')
			f = -1;
	}
	for (; isdigit(c); c = gc()) {
		k = k * 10 + (c - '0');
	}
	return f * k;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
}
