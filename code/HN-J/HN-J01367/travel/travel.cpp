#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c2[2]>='A'&&c2[2]<='C'){
		f1=0;
	}else{
		f1=1;
	}
	if(c4[2]>='A'&&c4[2]<='C'){
		f2=0;
	}else{
		f2=1;
	}
	if(c1==c3){
		cout<<'1';
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<'1';
			if(f1==f2){
				cout<<1;
				if(c2[2]-c4[2]==1||c4[2]-c2[2]==1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"00";
			if((c2[1]-c4[1]==1||c4[1]-c2[1]==1)&&c2[2]==c4[2]){
				cout<<'1';
			}else{
				cout<<'0';
			}
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
