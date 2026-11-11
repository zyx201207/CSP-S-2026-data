#include <bits/stdc++.h>
using namespace std;

string er(int a){
	string s;
	while(a > 0){
		s = char(a % 2 )+ s;
		a = a / 2;
	}
	return s;
}

int ad(string a, string b){
	int q =  max(a.size() , b.size());
	int p = min(a.size() , b.size());
	for(int i = 1;i <= q - p;i++){
		if(p == a.size()){
			a = '0' + a;
		}else{
			b = '0' + b;
		}
	}
	string k;
	for(int i = 1;i <= q;i++){
		if(a[i] == '0' || b[i] == '0'){
			k = k + '0';
		}else{
			k = k + '1';
		}
	}
	int he;
	for(int i = k.size();i >= 0; i--){
		int y = 1;
		he = he + k[i] * y;
		y = y * 2;
	}
	return he;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n ,m;
	cin >> n >> m;
	int w[n];
	for(int j = 0;j < n;j++){
		cin >> w[j];
	}
	
	return 0;
}
