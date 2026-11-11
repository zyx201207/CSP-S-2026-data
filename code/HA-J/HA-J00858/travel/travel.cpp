#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct abc{
	int car;
	string seat;
}r,x;
string x_pai,r_pai;
signed main(){
	freopen("travel5.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin >> r.car >> r.seat;
	cin >> x.car >> x.seat;
	for (int i = 0;i<=1;i++){
		x_pai += x.seat[i];
		r_pai += r.seat[i];
	}
	int flag = 1;
	if (r.car == x.car){
		cout << 1;
		if (x_pai == r_pai){
			cout << 1;
			if (r.seat[2] > 'C' && x.seat[2] > 'C'){
				cout << 1;
				if (x.seat[2]-r.seat[2] == 2 || x.seat[2]-r.seat[2] == -2){
					cout << 1;
					flag = 0;
				}else cout << 0;
			}
			else if (r.seat[2] <= 'C' && x.seat[2] <= 'C'){
				cout << 1;
				if (x.seat[2]-r.seat[2] == 1 || x.seat[2]-r.seat[2] == -1){
					cout << 1;
				}else cout << 0;
			}
			else cout << 0 << 0;
		}else cout << 0 << 0 << 0;
	}else cout << 0 << 0 << 0 << 0;
	return 0;
}
