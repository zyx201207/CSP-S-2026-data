#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
string f(int n){
	string ans = "";
	while(n > 0){
		char ch = n%2 + '0';
		ans = ch + ans;
		n /= 2;
	}
	return ans;
}
bool cmp(string s1, string s2){
	if(s1.size() != s2.size()){
		return s1.size() > s2.size();
	}else{
		return s1 > s2;
	}
	
}
int g(string s){
	int ans;
	for(int i = 0; i < s.size(); i++){
		ans += (s[i]-'0') * pow(2, s.size()-i-1);
	}
	return ans;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> vec;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		vec.push_back(f(a[i]));
	}
	sort(vec.begin(), vec.end(), cmp);
	long long ans = g(vec[0]);
	for(int i = 1; i < m; i++){
		ans = ans ^ g(vec[i]);
	}
	cout << ans;
	return 0;
}
