#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5; 

int c , t;
int n , d;
int sum;

int a[MAXN];

int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	while(t--){
		for(int i = 1; i <= n ; i++)
			a[i] = 0;
		cin >> n >> d;
		sum = 0;
		for(int i = 1; i <= n ; i++)
			cin >> a[i];
		for(int i = 1; a[i] < a[1] + 2 * d; i++){
			sum++;
		}
		cout << n - sum + 1;
	}
}
