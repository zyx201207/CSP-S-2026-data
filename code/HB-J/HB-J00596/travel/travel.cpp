#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b-d<=5){
			cout<<"1";
			if(b-d<=2){
				cout<<"1";
				if(b-d==1||b-d==-1){
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
}
