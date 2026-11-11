//GZ-J00527 谢明泽  兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool tt[10]{0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a==c){
		cout << 1;
		if((b[0] == d[0]) && b[1] == d[1]){
				cout << 1;
				if(int(b[2])<=67 &&int(d[2]) <= 67 || int(b[2]) >67&&int(d[2]) > 67){
					cout << 1;
					if(int(b[2]) - int(d[2]) == 1 || int(b[2]) - int(d[2]) == -1){
						cout << 1 ;
					}
					else{
						cout << "0";
					}
				}
				else{
					cout << "00";
				}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
