#include <bits/stdc++.h>
using namespace std;
int n;
string s,d;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	
	for(int i=0;i<n;i++){
		string a;
		int b;
		cin >>b;
		cin >> a;
		for(int j=0;j<b;j++){
			s = s+a;
		}
	}
	cout << 0;
	return 0;
}
