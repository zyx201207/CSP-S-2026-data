#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("string.in" , "r" , stdin);
	freopen("sting.out" , "r" , stdout);
	string s = "";
	int n = 0;
	cin >> n;
	long long z = 0;
	int flag = 0;
	for(int i = 0;i < n;i++){
		int m =  0;
		string k = "";
		cin >> m >> k;
		for(int j = 0;j < m;j++){
			s += k;
		}
		z += m;
	}
	for(int m = 0;m < z / 2;m++){
		if(s[m] != s[z-1-m]){
			++flag;
		}
	}
	cout << flag;
	return 0;
}
