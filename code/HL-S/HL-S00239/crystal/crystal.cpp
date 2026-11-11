#include <bits/stdc++.h>
using namespace std;

long long n, m;
struct Edge{
	long long zhi;
	long long ch;
}a[500005];
bool cmp(Edge x, Edge y){
	return x.ch < y.ch;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i].zhi;
		a[i].ch = a[i].zhi-a[i-1].zhi;
		if(a[i].zhi == a[i-1].zhi){
			cnt++;
			a[i-1].zhi = 999999;
		}
	}
	a[1].ch = 9999999;
	sort(a+1, a+n+1, cmp);
	for(int i = 1;i <= n;i++){
		if(m-a[i].ch >= 0){
			m-=a[i].ch;
			cnt++;
		}
		else{
			break;
		}
	}
	
	cout << cnt;
	return 0;
}
