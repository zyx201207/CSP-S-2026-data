#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int myc,yourc;
	string yours,mys;
	cin >> myc >> mys >> yourc >> yours;
	if(myc != yourc){
		cout << "0000";
		return 0;
	}else{
		cout << '1';
		if(mys[0] == yours[0] && mys[1] == yours[1]){
			cout << '1';
			if(mys[2] >= 'A' && mys[2] <= 'C' && yours[2] >= 'A' && yours[2] <= 'C') cout << '1';
			else if((mys[2] == 'D' || mys[2] == 'F') && (yours[2] == 'D' || yours[2] == 'F')) cout << '1';
			else cout << '0';
			if(mys[2] >= 'A' && mys[2] <= 'C' && yours[2] >= 'A' && yours[2] <= 'C' && abs(mys[2] - yours[2]) == 1) cout << 1;
			else if((mys[2] == 'D' || mys[2] == 'F') && (yours[2] == 'D' || yours[2] == 'F')) cout << '1';
			else cout << 0;
		}
		else{
			cout << "000";
			return 0;
		}
	}
	return 0;
}
