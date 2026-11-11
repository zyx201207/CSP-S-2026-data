#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	cin.tie(0);
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	int n;cin >> n;
	int a[n];
	char c[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	string st = "";
	for (int i=0;i<n;i++){
		st[i] = a[i]+c[i];
	}
	
	ll sl = rand() * n;
	
	cout << sl;
	
	
	
	
	
	
	return 0;
}
