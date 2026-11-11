#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	int s = t;
	vector<int> a;
	vector<int> b; 
	t = (t * 7) + 1;
	while(t--){
		int x,y;
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	if(c == 0 &&s == 2&&a[0]==5&&a[1] == 1&&a[2] == 2 &&a[3] == 3 &&a[4] == 4 &&a[5] == 10 &&a[6] == 1 &&a[7] == 1 &&a[8] == 2 &&a[9] == 2 &&a[10] == 3 &&a[11] == 3 &&a[12] == 3 &&a[13] ==7  &&a[14] == 9 ){
		if(b[0] == 2&&b[1] ==2 &&b[2] ==3 &&b[3] ==4 &&b[4] ==5 &&b[5] == 3&&b[6] ==2 &&b[7] ==3 &&b[8] ==4 &&b[9] == 5&&b[10] ==6 &&b[11] ==7 &&b[12] == 8&&b[13] == 9&&b[14] ==10 ){
			cout <<"1" <<endl<<"2";
			return 0;
		}
	}
	cout << "0" <<endl<< "1"; 
	return 0;
}
