#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cf,cs,df,ds;
	cin >> cf >> cs >> df >> ds;
	
	if(cf == df) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	
	bool t = true;
	if(cs[0]==ds[0]&&cs[1] ==ds[1]){
		t = true;
		cout << 1;
	} 
	else {
		t = false;
		cout << 0;
	}
	
	bool f = true;
	if(t&&(cs[2]<='C'&&ds[2]<='C'&&cs[2]>='A'&&ds[2]>='A'||cs[2]>='D'&&ds[2]>='D'&&cs[2]<='E'&&ds[2]<='E'))
		cout << 1;
	else {
		cout << 0;
		f = false;
	}
	
	
	if(abs(cs[2]-ds[2]) == 1 && t&&f)	cout << 1;
	else cout << 0 ;
	return 0;
}
