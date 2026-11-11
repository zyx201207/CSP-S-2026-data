#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string num,cnt;
	char a[3],b[3];
	cin >> num >> a >> cnt >> b;
	if(num == cnt){
		cout << 1;
		if(a[0] == b[0] && a[1] == b[1]){
			cout << 1;
			if((a[2] <= 'C' && b[2] <= 'C') || ((a[2] == 'F' && b[2] == 'D') || (b[2] == 'F' && a[2] == 'D'))){
				cout << 1;
				if(((a[2] == 'F' && b[2] == 'D') || (b[2] == 'F' && a[2] == 'D')) || (a[2] + 1 == b[2]) || (a[2] - 1 == b[2])){
					cout << 1;
				}else{
					cout << 0;
					return 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}
