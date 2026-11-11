#include<iostream>
#include<string>
using namespace std;
string c,s,c1,s1;
bool e1,e2,e3,e4;
void f1(string x,string y){
	if(x == y){
		e1 = true;
	}else{
		e1 = false;
	}
	cout << e1;
	return ;
}
void f2(string q,string p){
	if(q[0] == p[0]&&q[1] == p[1]&&e1 == true){
		e2 = true;
	}else{
		e2 = false;
	}
	cout << e2;
	return ;
}
void f3(string k,string g){
	bool i = (k[2] == 'A'||k[2] == 'B'||k[2] == 'C'&&g[2] == 'A'||g[2] == 'B'||g[2] == 'C');
	bool j = (k[2] == 'D'||k[2] == 'F'&&g[2] == 'D'||g[2] == 'F');
	bool w = (i == true||j == true);
	if(w == true&&e2 == true){
		e3 = true;
	}else{
		e3 = false;
	}
	cout << e3;
	return ;
}
void f4(string m,string n){
	bool r = (m[2] == 'A'&&n[2] == 'B');
	bool r1 = (m[2] == 'B'&&n[2] == 'A'||n[2] == 'C');
	bool r2 = (m[2] == 'C'&&n[2] == 'B');
	bool r3 = (m[2] == 'D'&&n[2] == 'F');
	bool r4 = (m[2] == 'F'&&n[2] == 'D');
	bool a = (r == true||r1 == true);
	bool b = (r2 == true||r3 == true);
	bool c = (a == true||b == true||r4 == true);
	if(c == true&&e2 == true){
		e4 = true;
	}else{
		e4 = false;
	}
	cout << e4;
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> c1 >> s >> s1;
	f1(c,s);
	f2(c1,s1);
	f3(c1,s1);
	f4(c1,s1);
	return 0;
}
