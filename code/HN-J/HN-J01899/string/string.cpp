#include<bits/stdc++.h>
#define unsigned long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,sum = 0;
	string s;
	cin >> n;
	int l = 0;
	for(int i = 1; i <= n; i++){
		int m;
		char a;
		cin >> m >> a;
		for(int i = 1; i <= m; i++){
			s[l] += a;
			l++;
		}
	}
	for(int i = 0,j = l - 1; i < j; i++,j--){
		if(s[i] != s[j]){
			sum++;
		} 
		
	}
	cout << sum;
	return 0;
}
