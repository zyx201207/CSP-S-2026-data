#include<bits/stdc++.h>
using namespace std;
string bus(int num) {
	int p[100000000];
	int l = 0;
	while(num > 1) {
		p[l] = num % 2;
		num /= 2;
		l++;
	}
	if (num == 1) {
		p[l] = 1;
	}
	string s;
	for(int i = l;i >=0; i--){
		s = s + to_string(p[i]);
	}
	return s;
}
string weiyv(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string s;
	if (a.size() < b.size()) {
		while(a.size() == b.size()) {
			a = a+"0";
		}
	}
	for(int i = 0; i < a.size(); i++){
		if (a[i] == '1' && b[i] == '1') {
			s = s + "1";
		}else {
			s = s +"0";
		}
	}
	reverse(s.begin(),s.end());
	return s;
}
long long n;
string a[100005]
int main(){
	freopen("and.in", "r",stdin);
	freopen("and.out","w",stdout);
	for(int i = 1; i  <= n; i++){
		cin >> a[i];
	}
	string max= "0";
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n;j++){
			if(weiyv(bus(a[i]),bus(a[j])) > max) {
				max = weiyv(bus(a[i]),bus(a[j]));
			}
		}
	}
	cout << max;
	return 0;
}
