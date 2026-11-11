#include <iostream>
using namespace std;
bool bx(int a,int b){
	if (a>=b) return a;
	else return b;
}
main(){
	string z[100],s[100];
	int n=0,m=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> z[i];
	}
	for (int i=1;i<=m;i++){
		int s[i];
	}
	int a=0,b=0;
	for(int i=1;i<=n;i++){
		int c=z[i+1];
		int d=z[i+2];
		a=bx(z[i],c);
		b=bx(c,d);
	}
	if (a<=b) cout << a;
	else cout << b;
	return 0;
}
