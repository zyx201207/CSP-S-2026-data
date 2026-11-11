#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool vis = false;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		vis = true;
	}else{
		vis = false;
		cout << 0;
	}
	if(vis){
		if(s1[0]+s1[1] == s2[0]+s2[1]){
			cout << 1;
			vis = true;
		}else{
			cout << 0;
			vis = false;
		}
	}else{
		cout << 0;
		vis = false;
	}
	if(vis){
		if(s1[2] <= 'C' && s2[2] <= 'C'){
			vis = true;
			cout << 1;
		}
		else if(s2[2] >= 'D' && s1[2] >= 'D'){
			cout << 1;
			vis = true;
		}
		else{
			cout << 0;
			vis = false;
		}
	}else{
		cout << 0;
		vis = false;
	}
	if(vis){
		if(s1[2]+1==s2[2] || s1[2]-1==s2[2]) cout << 1;
		else cout << 0;
	}else cout << 0;
	return 0;
}
