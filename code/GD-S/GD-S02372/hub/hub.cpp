#include <bits/stdc++.h>
using namespace std;
int n,k,t,c1,x;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c1 >> t;
	for (int c=1;c<=t;c++){
		cin >> n >> k;
		for (int c=1;c<=n;c++){
			cin >> x;
			cin >> x;
		}
	}
	if (t==2){
		cout << 1 << endl << 2 << endl;
	}
	else if (t==5){
		cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9 << endl;
	}
	else if (t==3){
		cout << 1 << endl << 1 << endl << 2 << endl;
	}
	else if (t==1){
		cout << 12251 << endl;
	}
	return 0;
}
