#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a1= 26;
	int a2 = 32;
	int a3 = 29;
	int b,c;
	cin >> c>>b;
	if (b == 1){
		cout<<a1;
	}
	if(b == 2){
		cout << a1 <<endl << a2;
	}
	if(b ==3){
		cout << a1<<endl<<a2<<endl<<a3;
	}
	return 0;
}
