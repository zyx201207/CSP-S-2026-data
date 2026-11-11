#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool check(char x,char y){
	if(x <= 'C' && y <= 'C') return 1;
	if(x >= 'D' && y >= 'D') return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin.tie(0) -> sync_with_stdio(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1 == b1){
		cout<<"1";
		if(a2[0] == b2[0] && a2[1] == b2[1]){
			cout<<"1";
			if(check(a2[2],b2[2])){
				cout<<"1";
				if(abs(a2[2] - b2[2]) == 1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
