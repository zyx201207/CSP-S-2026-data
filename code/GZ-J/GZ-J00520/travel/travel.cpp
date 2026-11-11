//准考证:GZ-J00520 学校:龙里县民族完全中学 姓名:李玮辰 
#include<bits/stdc++.h>
using namespace std;
bool ok(char&a,char&b){
	if(a=='F'&&b=='D'||a=='D'&&b=='F')return 1;
	if((a=='F'||a=='D')&&(b!='F'||b!='D'))return 0;
	if((b=='F'||b=='D')&&(a!='F'||a!='D'))return 0;
	return 1;
}
bool ok111(char&a,char&b){
	if(abs(a-b)==1)return 1;
	if(a=='F'&&b=='D'||a=='D'&&b=='F')return 1;
	return 0;
}
int main(){
	string ac,bc,az,bz;
	cin>>ac>>az>>bc>>bz;
	if(ac==bc){
		cout<<1;
		if(az.substr(0,2)==bz.substr(0,2)){
			cout<<1;
			if(ok(az[2],bz[2])){
				cout<<1;
				if(ok111(az[2],bz[2])){
					cout<<1;
				}else cout<<0;
			}else cout<<0;
		}else cout<<0;
	}else{
		cout<<"0000";
	}
	return 0;
}
