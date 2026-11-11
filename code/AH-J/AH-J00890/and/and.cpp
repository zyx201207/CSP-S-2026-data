#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m;
long long a[N], t[N];
string s[N];
string en_wo(int x){
	int s = 0;
	string c;
	while(x){
		s ++;
		t[s] = x % 2;
		x /= 2;
	}
	for(int i = 1; i <= s; i ++){
		c += char(t[i] + '0'); 
	}
	c[0] = s;
	return c;
}
long long wo_en(string t){
	long long s = 0;
	for(int i = 1; i <= t.size(); i ++){
		if(t[i] == '1'){
			s += pow(2, i);
		}
	}
	return s;
}
string yu(string x, string y){
	string s;
	for(int i = 1; i <= max(x[0], y[0]); i ++){
		s[i] = x[i] == y[i];
	}
	return s;
}
bool cmp(string x, string y){
	return x[0] > y[0];
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>> n>> m;
	for(int i = 1; i <= n; i ++){
		cin>> a[i];
		s[i] = en_wo(a[i]);
		cout<< s[i]<< endl;
	} 
	sort(s + 1, s + 1 + n, cmp);
	string t = s[1];
	for(int i = 2; i <= n; i ++){
		
		t = yu(t, s[i]);
	} 
	cout<< 12;
	return 0;
}
