#include <bits/stdc++.h>
using namespace std;
int a;
long long sum = 0;
char c;
string ans;
int f(string ans){
	int len = ans.size();
	for(int i = 0; i <= len / 2; i++){
		if(ans[i] != ans[len - i - 1]){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> c;
		for(int j = 0; j < a; j++){
		 	ans += c;
		}
	}
	f(ans);
	cout << sum;
	return 0;
} 
