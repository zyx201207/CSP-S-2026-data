#include<bits/stdc++.h>
using namespace std;
string _c1,_x1,_c2,_x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>_c1>>_x1>>_c2>>_x2;
	if(_c1[0]==_c2[0]&&_c1[1]==_c2[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(_x1[0]==_x2[0]&&_x1[1]==_x2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((_x1[2]<='C'&&_x2[2]<='C')||(_x1[2]>='D'&&_x2[2]>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(int(_x1[2]-'0')-int(_x2[2]-'0'))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
