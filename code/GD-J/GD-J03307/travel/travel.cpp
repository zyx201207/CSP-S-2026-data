#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string r_cx,r_zw;
	string x_cx,x_zw;
	int num = 1;
	cin >> r_cx >> r_zw >> x_cx >> x_zw;
	if(r_cx == x_cx){
		cout << "1";
	}else{
		cout << "0";
		num = 0;
	}
	if(r_zw[0] == x_zw[0] && r_zw[1] == x_zw[1] && num == 1){
		cout << "1";
	}else{
		cout << "0";
		num = 0;
	}
	if(r_zw[2] <= 'C' && x_zw[2] <= 'C' && num == 1){
		cout << "1";
	}else if(r_zw[2] >= 'D' && x_zw[2] >= 'D' && num == 1){
		cout << "1";
	}else{
		cout << "0";
		num = 0;
	}
	if(r_zw[2]+1 == x_zw[2] && num == 1){
		cout << "1";
	}else if(x_zw[2]+1 == r_zw[2] && num == 1){
		cout << "1";
	}else{
		cout << 0;
	}
	
	return 0;
}
