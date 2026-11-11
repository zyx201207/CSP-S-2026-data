#include <bits/stdc++.h>
using namespace  std;
int main(){
// freogeo("string.in ",""r" stdin);
// freogeo("string.out ",""w" stdout);
    int n;
	cin >> n;
	int a1;
	string c1;
	string m;
	for(int i=1;i<=n;i++){
		cin >> a1 >> c1;
		for(int i=0;i<a1-1;i++){
		    cin >> m;
		}
	}
		for(int i=0;i<a1-1;i++){
			cout << m;
		}
	return 0;
}
