#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx1,cx2;
	string zw1,zw2;
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2){
		cout<<1;
	}else{
		cout<<0;
	}
	int zw1h,zw2h;
	zw1h=(zw1[0]-'0')*10+(zw1[1]-'0');
	zw2h=(zw2[0]-'0')*10+(zw2[1]-'0');
//	cout<<"²éÕÒ"<<zw1h<<" "<<zw2h;
	char zw1c,zw2c;
	zw1c=zw1[2];
	zw2c=zw2[2];
//	cout<<zw1c<<" "<<zw2c;
	if(zw1h==zw2h){
		if(cx1==cx2){
			cout<<1;
		}
		else cout<<0;
	}else{
		cout<<0;
	}
	if(zw1h==zw2h){
		if(zw1c=='A'||zw1c=='B'||zw1c=='C'){
			if(char(zw2c)=='A'||char(zw2c)=='B'||char(zw2c)=='C'){
				if(cx1==cx2){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}
		else if(zw1c=='D'||zw1c=='F'){
			if(char(zw2c)=='D'||char(zw2c)=='F'){
				if(cx1==cx2){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0;
		}else{
			cout<<0;
		}
	}
	else cout<<0;
	if(cx1==cx2){
		if(zw1h==zw2h){
			if((zw1c=='A'&&zw2c=='B')||(zw1c=='B'&&zw2c=='A')||(zw1c=='C'&&zw2c=='B')||(zw1c=='B'&&zw2c=='C')||(zw1c=='D'&&zw2c=='F')||(zw1c=='F'&&zw2c=='D')){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
