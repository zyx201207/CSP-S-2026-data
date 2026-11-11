#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,zw1,zw2,m;
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2){
		m=m+'1';
	}else{
		cout<<"0000";
		return 0;
	}if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]){
		m=m+'1';
	}else{
		cout<<"1000";
		return 0;
	}if((zw1[2]=='F'||zw1[2]=='E')&&(zw2[2]=='F'||zw2[2]=='E')){
		cout<<"1111";
		return 0;
	}else if((zw1[2]=='A'||zw1[2]=='B'||zw1[2]=='C')&&(zw2[2]=='A'||zw2[2]=='B'||zw2[2]=='C')){
		m=m+'1';
		if(zw1[2]=='B'||zw2[2]=='B'){
			cout<<"1111";
		}else{
			cout<<"1110";
		}
	}else{
		cout<<"1100";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
