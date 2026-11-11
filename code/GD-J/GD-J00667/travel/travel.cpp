#include <bits/stdc++.h>
using namespace std;

void fileIO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
}

int main(){
	fileIO("travel");
	fastIO();
	string r1,r2,x1,x2;
	cin >> r1 >> r2 >> x1 >> x2;
	bool flag = true;
	if (r1 == x1){
		cout << 1;
	}
	else{
		cout << 0;
		flag = false;
	}
	if (flag == true && r2[0] == x2[0] && r2[1] == x2[1]){
		cout << 1;
	} 
	else{
		cout << 0;
		flag = false;	
	}
	if (flag == true){
		if (abs(x2[2]-r2[2]) == 1){
			if ((x2[2]=='D' && r2[2]=='C') || (x2[2]=='C' && r2[2] == 'D')){
				cout << 0;
				flag = false;
			}
			else if(abs(x2[2]-r2[2]) == 2){
				if (!((x2[2] == 'A' && r2[2] == 'C') || (x2[2] == 'C' && r2[2] == 'A'))){
					cout << 0;
					flag == false;
				}
			}
		}
		else{
			cout << 0;
		}
		if (flag == true){
			cout << 1;
		}
	}
	else{
		cout << 0;
	}
	if (flag == true){
		if (abs(x2[2]-r2[2]) == 1){
			cout << 1;
		} 
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	} 
	
	return 0;
}
