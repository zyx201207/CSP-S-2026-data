#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check1(string r2, string x2){
	string tmpr="", tmpx="";
	for (int i=0; i<2; i++){
		tmpr += r2[i];
	}
	for (int i=0; i<2; i++){
		tmpx += x2[i];
	}
	if (tmpr == tmpx){
		return 1;
	}
	return 0;
}

bool check2(string r2, string x2){
	int tmpr=r2[2]-'A', tmpx=x2[2]-'A';
	if (tmpr<3&&tmpx<3 || tmpr>=3&&tmpx>=3){
		return 1;
	}
	return 0;
}

bool check3(string r2, string x2){
	int tmpr=r2[2]-'A', tmpx=x2[2]-'A';
	if ((abs(tmpr-tmpx)==1||tmpr==3&&tmpx==5) && !(tmpr==2 && tmpx==3)){
		return 1;
	}
	return 0;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string r1,r2,x1,x2;
	cin >> r1 >> r2 >> x1 >> x2;
	
	if (r1 == x1){
		cout << 1;
		if (check1(r2,x2)){
			cout << 1;
			if (check2(r2,x2)){
				cout << 1;
				if (check3(r2,x2)){
					cout << 1;
				}
				else{
					cout << 0;
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
	else cout << "0000";
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
