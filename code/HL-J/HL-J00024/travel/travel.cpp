#include<bits/stdc++.h>

using namespace std;

int rx,xx;//小R的车厢：rx,小x的车厢：xx
string rh,xh;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> rx >> rh >> xx >> xh;
	if(rx != xx){//如果不在一个车厢里
		cout << "0000";
	}else{//如果在一个车厢里
		cout << 1;
		if(rh[0] == xh[0] && rh[1] == xh[1]){//如果在同一排里
			cout << 1;
			if(((rh[2] >= 'A' && rh[2] <= 'C') && (xh[2] >= 'A' && xh[2] <= 'C')) || ((rh[2] >= 'D' && rh[2] <= 'F') && (xh[2] >= 'D' && xh[2] <= 'F'))){
				cout << 1;
				if(int(abs(rh[2] - xh[2])) == 1){
					cout << 1;
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}
	return 0;
}
