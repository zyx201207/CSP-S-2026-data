#include<bits/stdc++.h>

using namespace std;
/*
scanf("%d", &x);
printf("%d", x);
*/
#define ll long long
const int N = 5e5 + 10, V = 210;


int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	
	int c, t;
	int n, k;
	cin >> c >> t;
	while(t--){
		cin>>n >> k;
		cout << abs((n + k) * (n - k) - n) << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
/*

*/
