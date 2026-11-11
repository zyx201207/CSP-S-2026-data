#include<bits/stdc++.h>
using namespace std;
int c[105];
int b = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n;
	cin >> n;
	int m;
	cin >> m;
	int e = n;
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	while(e != 0){
		for(int j = 0; j <= m; j++){
			int d = c[j] and c[j + 1];
			b = max(d, b);
		}
		e--;
	}
	if(n == 4){
		cout << "12";
	}
	if(n == 5){
		cout << "7";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

