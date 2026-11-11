#include <bits/stdc++.h>
using namespace std;
bool tihuan(string q , string p , int o){ 
	for(int i = 0 ; i < q.size() ; i++){
		if(o == 0){
			return 0;
		}
		if(q == p){
			//cout << q << " " << p << endl;
			return q == p;
		}
		if(q[i + 1] == p[i + 1]){
			q[i] = p[i];
		}
		else{
			q[i] = p[i];
		}
		o--;
	}
}
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	string s;
	while(n--){
		int a;
		char c;
		cin >> a >> c;
		string x;
		for(int i = 1 ; i <= a ; i++){
			x += c;
		}
		s += x;
	}
	//cout << s << endl;
	string m1 , m2;
	for(int i = 0 ; i <= s.size() / 2 - 1; i++){
		m1 += s[i];
	}
	if(s.size() % 2 == 0){
		for(int i = s.size() - 1 ; i >= s.size() / 2; i--){
			m2 += s[i];
		}
	}
	else{
		for(int i = s.size() - 1 ; i >= s.size() / 2 + 1; i--){
			m2 += s[i];
		}
	}
	if(m1 == m2){
		cout << 0;
		return 0;
	}
	//cout << m1 << " " << m2 << endl;
	int cnt = 0;
	for(int i = 1 ; i <= s.size() ; i++){
		if(tihuan(m1 , m2 , i)){
			cout << cnt;
			return 0;
		}
		cnt++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
