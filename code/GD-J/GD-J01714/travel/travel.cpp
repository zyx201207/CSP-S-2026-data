#include<bits/stdc++.h>
using namespace std;
bool solve1(string a,string b){
	for(int i = 0;i < 2;i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}
bool solve2(string a,string b){
	for(int i = 0;i < 2;i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(solve1(c1,c2) == true){
		cout << 1;
		if(solve2(s1,s2) == true) cout << 1;
		else{
			cout << "000";
			return 0;
		}
		if(s1[2] >= 'D' && s1[2] <= 'F' && s2[2] <= 'F' && s2[2] >= 'F'){
			cout << 1 << 1;
		}else if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
			cout << 1;
			if(s1[2] >= 'A' && s1[2] <= 'B' && s2[2] >= 'A' && s2[2] <= 'B'){
				cout << 1;
			}else if(s1[2] >= 'B' && s1[2] <= 'C' && s2[2] >= 'B' && s2[2] <= 'C'){
				cout << 1;
			}
		}else{
			cout << "00";
		}
	}else{
		cout << "0000" << endl;
	}
	return 0;
}
