#include<bits/stdc++.h>
using namespace std;
int n, t[200005], cnt, ans;
string x[200005];

string one(int a){
	int m = t[1];
	for(int i = 1; 1; i++){
		if(a <= m){
			return x[i];
		}
		else{
			m = m + t[i+1];
		}
	}
}
string two(int a){
	int m = cnt - t[n] + 1;
	for(int i = n; 1; i--){
		if(a >= m){
			return x[i];
		}
		else{
			m = m - t[i-1];
		}
	}
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t[i]; //多少个字母
		cnt += t[i]; //S的总长度
		cin >> x[i]; //什么字母 
	}
	
	for(int i = 1; i <= cnt/2; i++){
		if(one(i) != two(cnt - i + 1)){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
