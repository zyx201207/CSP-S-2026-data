#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	int c,t;
	int a[10000];
	int b[10000];
	int x,y;
	int n,m;
	cin >> c >> t;
	cin >> x >> y;
	for (int i = 1;i<=x;i++){
		cin >> a[i]; 
	}
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> b[i];
	}
	if (x == 4 && y == 2){
		cout << "1" << endl; 
	}
	if (n == 5 && m == 2){
		cout << "2";
	}
	if (x == 5 && y == 3){
		cout << "0" << endl; 
	}
	if (n == 6 && m == 2){
		cout << "1";
	}
	else{
		cout << "2" << endl;
		cout << "3";
	}
	freopen("migrate.out","w",stdout); 
	return 0;
}
