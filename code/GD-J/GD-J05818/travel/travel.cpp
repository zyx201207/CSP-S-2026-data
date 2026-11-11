#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx,sx,cy,sy;
	cin>>cx>>sx>>cy>>sy;
	if(cx[1]==cy[1]&&cx[0]==cx[0]){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(sx[0]==sy[0]&&sx[1]==sy[1]){
		cout<<'1';
		if(sx[2]<='C'&&sy[2]<='C'){
			cout<<'1';
			if(sx[2]=='B'||sy[2]=='B'){
				cout<<'1';
			}else{
				cout<<'0';
			}
		}else if(sx[2]>='D'&&sy[2]>='D'){
				cout<<"11";
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
} 
