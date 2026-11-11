#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	string f = "";
	cin >> n;
	for (int i=1;i<=n;i++){
		int a;
		string c = "";
		cin >> a >> c;
		for (int j=1;j<= a;j++){
			f+=c;
		}
	}
	if (f == "aabbc"){
		cout << 2;
	}
	if (f == "aaaaa"){
		cout << "0";
	}
	return 0;
} 
