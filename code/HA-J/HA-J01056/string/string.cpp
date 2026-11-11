#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N], n;
long long int anss, lenn, midd;
char c[N];
bool b;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		cin >> c[i];
		lenn += a[i];
	}
	if((lenn&1)){
		b = 1;
		midd = lenn/2+2;
	}else{
		b = 0;
		midd = lenn/2+1;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			s += c[i];
		}
	}
	for(int i = midd;i <= lenn;i++){
		if(s[i-1] != s[lenn-i]){
			anss++;
		}
	}
	cout << anss;
	return 0;
} 
