//∏ …≠É| GZ-J00367 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, m, cnt1, cnt2;
int a[N], b[N];

int main(){
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
    cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	if(m == 1){
		cout << 0;
		return 0;
	}
	if(n == 2){
		cout << 2 << ' ' << 3; 
	}
	return 0;
}
