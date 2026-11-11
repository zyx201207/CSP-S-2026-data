#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans11=(c1[0]-'0')*10+(c1[1]-'0');
	int ans12=(c2[0]-'0')*10+(c2[1]-'0');
	if(ans11==ans12){
		cout<<'1';
		int ans21=(s1[0]-'0')*10+(s1[1]-'0');
		int ans22=(s2[0]-'0')*10+(s2[1]-'0');
		if(ans21==ans22){
			cout<<'1';
			char ans31=s1[2];
			char ans32=s2[2];
			int flg=false;
			if(ans31>'C' && ans32>'C'){
				cout<<"11";return 0;
			}else if(ans31<='C' && ans32<='C'){
				flg=true;
			}else{
				flg=false;
			}if(flg){
				cout<<'1';
				if(abs(ans31-ans32)==1){
					cout<<'1';return 0;
				}else{
					cout<<'0';return 0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
