#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, m, x, y;
// nÊÇ³µÏáºÅ£¬mÊÇÅÅ 
char a, b;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n;
	if(n == 0){
		cin >> n;
	}
	cin >> m;
	if(m == 0){
		cin >> m;
	}
	cin >> a;
	
	cin >> x;
	if(x == 0){
		cin >> x;
	}
	cin >> y;
	if(y == 0){
		cin >> y;
	}
	cin >> b;
	
	if(n == x){
		cout << 1;
		if(m == y){
			cout << 1;
			if(a <= 'C' && b <= 'C'){
				cout << 1;
				if(a - 1 == b || a + 1 == b){
					cout << 1;
				}else{
					cout << 0;
				}
			}else if(a > 'C' && b > 'C'){
				cout << 1 << 1;
			}else{
				cout << 0 << 0;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
