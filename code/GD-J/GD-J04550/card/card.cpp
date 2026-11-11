#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1000010], t[1000010], c[1000010],ans[1000010] ;
int sum = 0 ;

void wzj(int a){
	t[++sum] = a;
} 
void czw(int b){
	sum = 0;
	for(int i = b; i <= n; i++){
		if(c[a[i]] && c[a[i]] <= sum && t[c[a[i]]] == a[i]){
			sum = c[a[i]];
		} else {
			wzj(a[i]);
			c[a[i]] = sum;
		}
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		memset(c, 0, sizeof(c)); 
		czw(i);
		for(int j = 1; j <= sum; j++){
			ans[t[j]] ++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " " ;
	}
	return 0;
}
