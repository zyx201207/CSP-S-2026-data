#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m;
struct node{
	long long x, y;
}a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(long long i = 1; i <= n; i ++ ){
		cin >> a[i].x;
		a[i].y = a[i].x - a[1].x;
	}
	for(long long i = 1; i <= n; i ++ ){
		for(long long j = n; j >= i + 1; j -- ){
			if(a[j].y - a[i].y == m){
				cout << j - i + 1;
				return 0;
			} 
		}
	}
	return 0;
} 
