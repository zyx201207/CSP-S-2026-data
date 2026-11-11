#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , m;
long long cnt;
struct node{
	long long a;
	int b = 0;
}p[N];
void fun(int x) {
	int k = p[x].a;
	while(k) {
		p[x].b++;
		k &= (k - 1);
	}
}
bool cmp(node x , node y) {
	if(x.b == y.b) 
	return x.a > y.a;
	else return x.b > y.b;
}
int main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> p[i].a;
		fun(i);
	}
	sort(p + 1 , p + n + 1 , cmp);
	cnt = p[1].a;
	for(int i = 2;i <= m;i++) {
		cnt &= (long long)p[i].a;
	}
	cout << cnt; 
	return 0;
}


