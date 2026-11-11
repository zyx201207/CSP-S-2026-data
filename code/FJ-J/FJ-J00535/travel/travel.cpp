#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4,b1,b2,b3,b4;
	cin>>a1>>a2>>b1>>b2;
	a3=a2[0]+a2[1];
	a4=a2[2];
	b3=b2[0]+b2[1];
	b4=b2[2];
	if(a1==b1){
		cout<<"1";
		if(a3==b3){
			cout<<"1";
			if((a4=="A"&&(b4=="B"||b4=="C"))||(a4=="B"&&(b4=="A"||b4=="C"))||(a4=="C"&&(b4=="B"||b4=="A"))||(a4=="D"&&b4=="F")||(a4=="F"&&b4=="D")){
				cout<<"1";
				if((a4=="A"&&b4=="B")||(a4=="B"&&(b4=="A"||b4=="C"))||(a4=="C"&&b4=="B")||(a4=="D"&&b4=="F")||(a4=="F"&&b4=="D")){
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
