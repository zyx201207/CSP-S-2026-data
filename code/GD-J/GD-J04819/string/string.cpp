#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
string zh(long long a){
	string s;
	if(a == 0){
		return "0";
	}
	while(a != 0){
		string s3;
		s3 += (a % 10) + '0';
		s = s3 + s;
		a /= 10;
	}
	return s; 
}
long long hz(string a){
	long long s = 0;
	for(int i = 0; i < a.size(); i++){
		s *= 10;
		s += a[i] - '0';
	}
	return s;
}
string qt(string s){
	string a;
	for(int i = 1; i < s.size(); i++){
		a += s[i];
	}
	return a;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sie = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> c[i];
		sie += a[i];
	}
	long long ban = 0;
	stack<string> f,g,f1,g1;
	long long pd;
	pd = sie / 2;
	int bj;
	
	for(int i = 0; i < n; i++){
		ban += a[i];
		if(ban > pd){
			bj = i;
			string s2;
			s2 += c[i];
			s2 += zh(ban - pd);
			string s1;
			s1 += c[i];
			s1 += zh(a[i] - (ban - pd));
			f.push(s1);
			g.push(s2);
			break; 
		}
	}
	for(int i = bj - 1; i >= 0; i--){
		string s;
		s += c[i];
		s += zh(a[i]);
		f.push(s);
	}
	for(int i = bj + 1; i < n; i++){
		string s;
		s += c[i];
		s += zh(a[i]);
		g.push(s);
	}
	long long ans = 0;
	while(!f.empty() && !g.empty()){
		string s1 = f.top();
		string s2 = g.top();
		f.pop();
		g.pop();
		string st1 = qt(s1);
		string st2 = qt(s2);
		if(s1[0] == s2[0]){
			if( (hz(st1)) > (hz(st2))){
				long long gd = (hz(st1)) - (hz(st2));
				char ls = s1[0];
				s1 = "";
				s1 += ls;
				s1 += zh(gd);
				f.push(s1);
			} else if( (hz(st1)) < (hz(st2))){
				long long gd = (hz(st2)) - (hz(st1));
				char ls = s2[0];
				s2 = "";
				s2 += ls;
				s2 += zh(gd);
				g.push(s2);
			}
		} else {
			if( (hz(st1)) > (hz(st2))){
				long long gd = (hz(st1)) - (hz(st2));
				ans += hz(st2);
				char ls = s1[0];
				s1 = "";
				s1 += ls;
				s1 += zh(gd);
				f.push(s1);
			} else if( (hz(st1)) < (hz(st2))){
				long long gd = (hz(st2)) - (hz(st1));
				ans += hz(st1);
				char ls = s2[0];
				s2 = "";
				s2 += ls;
				s2 += zh(gd);
				g.push(s2);
			} else {
				ans += hz(st2);
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
