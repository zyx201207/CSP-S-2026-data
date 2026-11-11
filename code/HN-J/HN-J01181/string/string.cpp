#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[n+10];
	string c;
	string s;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i]  >>  c[i];
	}
	
	for(int i = 0;i < n;i++){
		int gs = a[i];
		for(int j = 1;j <= gs;j++){
			s += c[i];
		}
	}
	
	int cs = 0;
	for(int l = 0,r = s.size();l <= r;l ++,r--){
		if(l != r)cs++;
	}
	cout << cs;
	return 0;
}
