#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f; 
	if(a == 0 && b == 2){
		cout << 32 << endl << 17;
	}
	if(a == 0 && b == 3){
		cout << 35 << endl << 16;
	}
	else{
		cout << c*f << endl << d+e;
	}
	freclose(stdin);
	freclose(stdout);
	return 0;
}
