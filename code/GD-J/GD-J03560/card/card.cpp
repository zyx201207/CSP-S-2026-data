#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cur = 1;
	for (int i = 2; i <= n; i++){
		if (a[i] == a[i - 1]){
			cur++;
		}
		else{
			cout << cur << " ";
			cur++;
		}
	}
	cout << cur;
	return 0;
}

//10:22 12pts
//11:49 jump then fall......
//100 + 100 + 40 + 12 = 252pts
//1= or 2= ? :(
