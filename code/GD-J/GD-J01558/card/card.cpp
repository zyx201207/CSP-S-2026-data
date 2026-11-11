#include<bits/stdc++.h>
using namespace std;
const int N  = 5e5 + 5;
int n , m , a[N];
struct node{
	int b , c , cnt;
}p[N];
set<int> s;
void fun(int x) {
	for(int i = x;i <= n;i++) {
		if(p[a[i]].b != 0) {
			p[a[i]].b = 0;
			p[a[i]].c = i;
			
		}else {
			for(int j = x;j <= i;j++)
		      p[a[i]].cnt++;
		}
	}
}
int main() {
	//freopen("card.in" , "r" , stdin);
	//freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++) {
		fun(i);
	} 
	for(int i = 1;i <= m;i++) cout << p[i].cnt << " ";
	return 0;
} 
