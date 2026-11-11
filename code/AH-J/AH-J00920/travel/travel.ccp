#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	int r=(s1[0]-'0')+s1[1];
	int x=(s2[0]-'0')+s2[1];
	if(r==x){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if((s1[2]>='D' && s2[2]>='D') || (s1[2]<='C' && s2[2]<='C')){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if(r-1==x || r+1==x){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
