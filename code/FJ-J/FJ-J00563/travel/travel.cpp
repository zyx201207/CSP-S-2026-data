#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string cr, sr, cx, sx;
	cin >> cr >> sr >> cx >> sx;
	if(cr == cx){
		cout << '1';
	} else{
		cout << "0000" << endl;
		return 0;
	}
	if(sr[0] == sx[0] && sr[1] == sx[1]){
		cout << '1';
	}else{
		cout << "000\n";
		return 0;
	}
	if((sr[2] <= 'C'&&sx[2] <= 'C')||(sr[2] >= 'D'&&sx[2] >= 'D')){
		cout << '1';
	}else{
		cout << "00\n";
		return 0;
	}
	if((max(sx[2], sr[2])-min(sx[2], sr[2]))==1&&max(sx[2], sr[2])!='D'){
		cout << "1\n";
	}else{
		cout << "0\n";
	}
	return 0;
}
