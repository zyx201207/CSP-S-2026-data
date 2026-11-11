#include<bits/stdc++.h>
using namespace std;
int cx1,zw1,cx2,zw2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>c1>>cx2>>zw2>>c2;
	if(cx1==cx2){
		cout<<"1";
		if(zw1==zw2){
			cout<<"1";
			if('A'<=c1&&c1<='C'&&'A'<=c2&&c2<='C'||'D'<=c1&&c1<='E'&&'D'<=c2&&c2<='E'){
				cout<<"1";
				if(abs(c1-c2)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
/*
02 01B 02 01A
*/
