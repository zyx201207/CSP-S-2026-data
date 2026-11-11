#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in",'R');
    //freopen("string.out",'W');
	string m;
	int n;
	string a;
	cin >> n;
	int h = 0;
	int y = 0;
	for(int i = 1;i <= n;i++){
		cin >> a;
	    y = a[0];
		for(int g = 1; g <= y; g++){
			m = m + a[1];
		}
	}
//	cout << m;
	cout << y;
	return 0;
}
