#include <bits/stdc++.h>
using namespace std;

int n, sum, s;
string a;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	while(n--){
		int x;
		char y;
		scanf("%d %c", &x, &y);
		while(x--)a[sum++] = y;
	}
	int l = 0, r = sum - 1;
	while(l <= r){
		if(a[l] != a[r])s++;
		l++;
		r--;
	}
	printf("%d", s);
	
	return 0;
}
