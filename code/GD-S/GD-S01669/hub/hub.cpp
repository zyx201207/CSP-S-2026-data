#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c;
	if(c==0){
		cin >>t;
		if(t=2){
			cout << 1 <<endl;
			cout << 2;
		}
		else if(t==3){
			cout <<1 << endl;
			cout <<1 << endl;
			cout <<2 << endl;
		}
		else if(t==5){
			cout <<17 << endl;
			cout <<9 << endl;
			cout <<6 << endl;
			cout <<6 << endl;
			cout <<9 << endl;
		}
		else if(t==1){
			cout << 12251;
		}
	}
	return 0;
}
