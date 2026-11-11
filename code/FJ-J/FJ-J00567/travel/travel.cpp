#include<bits/stdc++.h>
using namespace std; 
string rx,ry,lx,ly;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>ry>>lx>>ly;
	if(rx!=lx){
		cout<<"0000";
	}else if(ry[0]!=ly[0]||ry[1]!=ly[1]){
		cout<<"1000";
	}else if((ry[2]<'D'&&ly[2]<'D')||(ry[2]>'C'&&ly[2]>'C')){
		if((ry[2]>'C'&&ly[2]>'C')||(int(ry[2])-int(ly[2])==1||int(ry[2])-int(ly[2])==-1)){
			cout<<"1111";
		}else cout<<"1110";
	}else{
		cout<<"1100";
	}
	return 0;
} 
