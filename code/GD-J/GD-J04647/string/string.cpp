#include <bits/stdc++.h>
using namespace std;
string c = "";
int cnt = 0;
long long n,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		string b;
		cin >> a >> b;
		for(int j = 1;j <= a;j++){
			l++;
			c += b;
		}
	}
	for(int i = 0;i <= l/2 - 1;i++){
		if(c[i] != c[l-i-1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
