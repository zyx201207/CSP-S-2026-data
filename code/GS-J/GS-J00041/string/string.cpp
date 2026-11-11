#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
//	vector<string> c0;
	long long a;
	string c1, c;
	for(int i = 0; i < n; i++){
		cin >> a;
		cin >> c1;
//		c0.push_back(c1);
//		c = c1;
		for(int j = 0; j < a; j++){
			c += c1; 
		}
//		c += c2;
//		c += c0[i];
	}
//	cout << c.size() << endl;
//	c0.clear();
	long long out = 0;
	for(long long k = 0; k < c.size()/2; k++){

		if(c[k]!=c[c.size()-k-1]){
			out++;
		}
	}
	cout << out;
	return 0;
}
	
