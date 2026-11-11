#include<bits/stdc++.h>
using namespace std;
long long n, a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
	    for(int j = 1; j <= a; j++){
		    s += c;
	    }
	}cout << "0";
	return 0;
}
