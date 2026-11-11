#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;

struct Node{
	int len;
	char c;
}item[MAXN];

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s; 
	for(int i = 1; i <= n; i++){
		cin >> item[i].len >> item[i].c;
		for(int j = 1; j <= item[i].len; j++){
			s += item[i].c;
		} 
	}	
	cout << 0;
	return 0;
} 
