//GZ-J00615 仇希臣
#include<iostream>
#include<bits/stringfwd.h>
namespace std{};
int main(){
	int n;
	cin >> n;
	long long a;
	string s;
	string b;
	for (int i = 1;i <= n;i++){
		cin >> a >> s;
		for (int j = 1;j <= a;j++){
			b[i] += s;
		}
	}
	string c;
	int cut = 1;
	for (int i = b.size();i > 0;i--){
		c[cut] = b[i];
		cut++;
	}
	if (c == b){
		cout << 0;
	}
	else{
		cout << 2;
	}
	return 0;
}
