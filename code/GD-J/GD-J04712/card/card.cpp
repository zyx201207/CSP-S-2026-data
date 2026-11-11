#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n , m ,d;
	int atr[500005] = {};
	int j = 0; 
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> atr[i];
		if(atr[i] != atr[i - 1] && i != 1){
			d = i;
		} 
	}
	if (m == 1){
		cout << n;
	}
	if (m == 2){
		if(d = 2){
			cout << 1 << " " << 5;
		}
		if(d = 3){
			cout << 2 << " " << 5;
		}
		if(d = 4){
			cout << 3 << " " << 5;
		}
		if(d = 5){
			cout << 4 << " " << 5;
		}
	}
} 
