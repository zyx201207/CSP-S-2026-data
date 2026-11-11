#include<bits/stdc++.h>
using namespace std;
string X,X1,R,R1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>X>>X1>>R>>R1;
	if(X==R){
		cout<<1;
		if(X1[0]+X1[1]==R1[0]+R1[1]&&X==R){
			cout<<1;
			if((X1[2]>='A'&&X1[2]<='C'&&R1[2]>='A'&&R1[2]<='C'&&(X1[2]=='B'||R1[2]=='B'))||(X1[2]>='D'&&X1[2]<='E'&&R1[2]>='D'&&R1[2]<='E')){
				cout<<1;
				if(abs(X1[2]-R1[2])==1){
					cout<<1;
				}else{
					cout<<0;
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
