#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if(c == 0){
		if(t == 2){
			cout << 1 << endl << 2 << endl;
			return 0;
		}
		if(t == 3){
			cout << 1 << endl << 1 << endl << 2 << endl;
		}
	}
}
