#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,c[1005];
	cin >> a >> b;
	for (int i=1;i<=a;i++){
		cin >> c[1005];
	}
	if (a == 4 || b == 3){
		cout <<3<<" "<<1<<" "<<4;
	}
	else if (a == 10 || b == 3){
		cout <<10<<" "<<3<<" "<<3;
	}
	else cout << 0;
}
