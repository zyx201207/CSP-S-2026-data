#include <bits/stdc++.h>
using namespace std;

int a[(int)2e5+4];
int s1(int a){	//统计二进制中1的个数 
	int sum = 0;
	while(a!=0){
		if(a&1==1) sum++;
		a>>=1;
	}
	return sum;
}

bool cmp(int x, int y){
	if(s1(x) != s1(y)) return s1(x) > s1(y);
	else return x > y;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1, cmp);
	long long mx = a[1];
	for(int i = 2; i <= m; i++) mx &= a[i];
	cout << mx;
	return 0;
}
