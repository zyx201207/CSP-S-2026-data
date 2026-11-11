#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
long long n, l;
struct node{
	int a;
	char c;
	int l, r;
}g[N];

ll h(ll x){
	return l - x + 1;
}
int half;
int half_s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> g[i].a >> g[i].c;
		g[i].l = g[i-1].r + 1;
		g[i].r = g[i].l + g[i].a - 1;
		l += g[i].a; 
	}
	for(int i = 1; i <= n; i ++){
		half_s += g[i].a;
		if(half_s >= l / 2){
			half = i;
			break;
		}
	}
	//cout << half << " half" << endl;
	int lz = 1;
	int rz = n;
	int hz = 0;
	int sum = 0;
	for(int i = 1; i <= half + 1; i ++){
		//cout << "now i  "<< i << endl;
		int len = g[i].a;
		int al = g[i].l;
		int ar = g[i].r;
		//cout << "now rz " << rz << endl; 
		while(hz <= len){
			if(hz + g[rz].a >= len){
				if(g[rz].c != g[i].c) {
					sum += len - hz;
				}
				break;
			}
			hz += g[rz].a;
			if(g[rz].c != g[i].c){
				sum += g[rz].a;
			}
			//cout << "rz " << rz << endl;
			rz --;
		}
		hz = 0;
	}
	cout << sum;
	return 0;
} 
/*
3
2 a
2 b
1 c

6
10000 a
10000 a
10000 a
10000 b
10000 b
10000 b
*/
