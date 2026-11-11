#include<bits/stdc++.h>
using namespace std;
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int main(){
    string c,z,c1,z1;
	cin>>c>>z>>c1>>z1;
	if(c!=c1&&z==z1){
		cout<<"0000";
	}if(c==c1){
		cout<<"1000";
	}
	if((int)z==(int)z1){
		cout<<"1100";

	}
	if((char)z-(char)z1<=3&&(char)z-(char)z1>=-3||(char)z-(char)z1<=2&&(char)z-(char)z1>=-2){
		cout<<"1110";
	}
	if((char)z-(char)z1<=1&&(char)z-(char)z1>=-1){
		cout<<"1111";
	}
	return 0;
}

