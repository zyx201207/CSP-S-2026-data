//T1 travel
#include <iostream>
#include <string>
using namespace std;
string a1,a2,b1,b2;
bool f1=false,f2=false,f3=false,f4=false;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a1>>a2>>b1>>b2;
	//1
	if (a1==b1) {
		cout<<1;
		f1=true;
	}
	else cout<<0;
	//2
	string t1=a2.substr(0,2);
	string t2=b2.substr(0,2);
	if (t1==t2 && f1) {
		cout<<1;
		f2=true;
	}
	else cout<<0;
	
	char c1=a2[2],c2=b2[2];
	//3
	if ('A'<=c1 && c1<='C' && 'A'<=c2 && c2<='C' && f2) {
		cout<<1;
		f3=true;
	}
	else if ('D'<=c1 && c1<='E' && 'D'<=c2 && c2<='E' && f2) {
		cout<<1;
		f3=true;
	}
	else cout<<0;
	//4
	if (c1+1==c2 && c1!='C' && c2!='D' && f3) {
		cout<<1;
		f4=true;
	}
	else cout<<0;
	
	return 0;
} 
