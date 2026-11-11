#include <bits/stdc++.h>
using namespace std;
int a[200010], cnt[200010];

string two(int x){
	string s1 = "", s2 = "";
	while(x != 0){
		s1 += char(x % 2);
		x /= 2;
	}
	for(int i=s1.size()-1; i>=0; i--){
		s2 += s1[i];
	}
	return s2;
}

string an(int x, string y){
	string s = "";
	int sum = 0, q = 1;
	for(int i=y.size()-1; i>=0; i--){
		sum += q * y[i];
		q *= 2;
	}
	
	int k = min(x, sum);
	int l = max(x, sum);
	cout << l << " " << k << endl;
	string a = two(l), b = two(k);
	
	for(int i=0, j=a.size()-b.size(); i<b.size(); i++, j++){
		if(b[i] == 1 and a[j] == 1) s += "1";
		else s += "0";
	}
	return s;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		for(int j=1; j<i; j++){
			if(a[i] > a[j]) swap(a[i], a[j]);
		}
	}
	string tmp = "1";
	for(int i=1; i<=m; i++){
		cout << a[i] << endl << endl;
		tmp = an(a[i], tmp);
	}
	int q = 1, sum = 0;
	for(int i=tmp.size()-1; i>=0; i--){
		sum += q * tmp[i];
		q *= 2;
	}
	cout << sum << endl;
	return 0;
}
