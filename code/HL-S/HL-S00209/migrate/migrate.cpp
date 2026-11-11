#include<bits/stdc++.h>                                                          
using namespace std;
const int N = 2000005;
int a[N];
int cnt;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	long long int n, d;
	cin >> c >> t;
	for(int j = 1; j <= t; j++){
		cin >> n >> d;
		for(int h = 2; h <= t; h ++)
			cin >> c >> t;
		for(int i = 1;i <= n; i++){
			cin >> a[i];
		}
	}
		if(n == 1 || n == 2 || n == 3){
			cout << 0 << endl;

		}
	for(int i = 1; i <= n; i++){
	
		if(a[i + 1] - a[i] < d){
			cout << 2 << endl;
	}	
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
