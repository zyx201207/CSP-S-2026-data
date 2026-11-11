#include <bits/stdc++.h>
using namespace std;

char s1,s2;
int c1,c2;
int r1,r2;
bool check(char a,char b){
	if (a>='A' && a<='C'&& b>='A' && b<='C') return 1;
	if (a>='D' && a<='F'&& b>='D' && b<='F') return 1;
	return 0;
} 
bool check2(char a,char b){
	if (a>='A' && a<='C'&& b>='A' && b<='C' && abs(a-b)==1) return 1;
	if (a>='D' && a<='F'&& b>='D' && b<='F'&& abs(a-b)==1) return 1;
	return 0;
}
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string r,x;
	string rs,xs;
	cin >> r >> rs >> x >> xs;
	
	r1 += r[0]-'0';
	r1*=10;
	r1+= r[1]-'0';
	r2 += x[0]-'0';
	r2*=10;
	r2+= x[1]-'0';
	for (int i=0;i<rs.size();i++){
		if (rs[i] >='A' && rs[i] <= 'Z'){
			s1 = rs[i];
		}else if (rs[i] >='1' && rs[i] <= '9'){
			c1*=10;
			c1+=rs[i]-'0';
		}
	}
	for (int i=0;i<xs.size();i++){
		if (xs[i] >='A' && xs[i] <= 'Z'){
			s2 = xs[i];
		}else if (xs[i] >='1' && xs[i] <= '9'){
			c2*=10;
			c2+=xs[i]-'0';
		}
	}
	if (r1!=r2){
		cout << "0000";
		return 0;
	}
	if (c1!=c2){
		cout << "1000";
		return 0;
	}
	if (!check(s1,s2)){
		cout << "1100";
		return 0;
	}
	if (!check2(s1,s2)){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
