#include<bits/stdc++.h>
using namespace std;
int main(){
	string a1,a2,b1,b2,z;
	cin>>a1>>a2>>b1>>b2;
	char a=a2[2],b=b2[2];
	if(a1==b1){
		cout<<'1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<'1';
			if(a<=67&&b<=67){
				cout<<'1';
				if(a==b+1||a==b-1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(a>67&&b>67){
				cout<<'1';
				if(a==b+2||a==b-2){
					cout<<'1';
				}else{
					cout<<'0';
				}
			
			}
			else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	return 0;
	
}