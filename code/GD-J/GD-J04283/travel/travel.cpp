#include<bits/stdc++.h>
using namespace std;
#define int long long

string cr,sr,cx,sx;
string rp,xp,rz,xz;
bool check_c(){
	if(rz == "A" || rz == "B" || rz == "C"){
		if(xz == "A" || xz == "B" || xz == "C") return true;
		else return false;
	}else{
		if(xz == "D" || xz == "F") return true;
		else return false;
	}
}
bool check_l(){
	if(rz == "A"){
		if(xz == "B")return true;
		else return false;
	}else if (rz == "B"){
		if(xz == "A" || xz == "C") return true;
		else return false;
	}else if(rz == "C"){
		if(xz == "B") return true;
		else return false;
	}else if(rz == "D"){
		if(xz == "F") return true;
		else return false;
	}else{
		if(xz == "D") return true;
		else return false;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	for(int i = 0;i < 3;i ++){
		if(i != 2){
			rp += sr[i];
			xp += sx[i];
		}else{
			rz = sr[i];
			xz = sx[i];
		}
	}
//	cout << rp << ' ' << xp << ' ' << rz << ' ' << xz << '\n';
	if(cr != cx){
		cout << "0000\n";
	}else{
		if(rp != xp){
			cout << "1000\n";
		}else{
			if(!check_c()){
				cout << "1100\n";
			}else{
				if(!check_l()){
					cout << "1110\n";
				}else{
					cout << "1111\n";
				}
			}
		}
	}
	return 0;
}
