#include<bits/stdc++.h>
using namespace std;
string a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>> a[1] >> a[2] >> a[3] >> a[4];
	if(a[1]!=a[3]){
		cout<<"0000";
		return 0;
	} 
	cout<<'1';
	if(a[2][0]!=a[4][0] || a[2][1] != a[4][1]){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if((a[2][2] == 'D' || a[4][2] == 'D')||(a[2][2] == 'F' || a[4][2] == 'F') ){
		if((a[2][2] == 'D' || a[4][2] == 'D')and(a[2][2] == 'F' || a[4][2] == 'F')){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	} 
	if(a[2][2]=='B' || a[4][2]=='B'){
		cout<<"11";
	}
	else{
		cout<<"10";
	}
	return 0;
} 
