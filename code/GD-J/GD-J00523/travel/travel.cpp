#include <iostream>
#include <string>
using namespace std;
int main(){
	string a1,a2,d1,d2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>d1>>d2;
	if(a1==d1){
		cout<<1;
		if(a2[0]+a2[1]==d2[0]+d2[1]){
			cout<<1;
			if(a2[2]>='A'&&a2[2]<='C'){
				if(d2[2]>='A'&&d2[2]<='C'){
					cout<<1;
					if(a2[2]=='B'||d2[2]=='B'){
						cout<<1; 
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			if(a2[2]>='D'&&a2[2]<='E'){
				if(d2[2]>='D'&&d2[2]<='E'){
					cout<<11;
				}
				else{
					cout<<"00";
				}
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
