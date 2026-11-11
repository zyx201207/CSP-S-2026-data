#include<iostream>
#include<cstdio>
#include<cmath>
#define gc getchar
using namespace std;
char st;
int read(){
	char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	int x = 0;
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = gc();
	}
	if(ch >= 'A' && ch <= 'F') st = ch;
	return x;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c1 = read(), s1 = read(), t1 = st;
	int c2 = read(), s2 = read(), t2 = st;
	if(c1 == c2){
		cout << 1;
		if(s1 == s2){
			cout << 1;
			if(t1 + t2 == 'D' + 'F' || max(t1, t2) <= 'C'){
				cout << 1;
				if((abs(t1 - t2) == 1 && min(t1, t2) != 'C') || t1 + t2 == 'D' + 'F') cout << 1;
				else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	return 0;
}
