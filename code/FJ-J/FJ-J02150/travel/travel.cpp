#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int car1,car2;
	string n1,n2;
	cin>>car1>>n1>>car2>>n2;
	if(car1==car2){
		cout<<1;
		if(n1[0]==n2[0]&&n1[1]==n2[1]){
			cout<<1;
			if(n1[2]>='A'&&n1[2]<='C'&&n2[2]>='A'&&n2[2]<='C'){
				cout<<1;
				if(abs(n1[2]-n2[2])==1){
					cout<<"1\n";
				}else{
					cout<<"0\n";
				}
			}else if(n1[2]>='D'&&n1[2]<='E'&&n2[2]>='D'&&n2[2]<='E'){
				cout<<"11\n";
			}else{
				cout<<"00\n";
			}
		}else{
			cout<<"000\n";
		}
	}else{
		cout<<"0000\n";
	}
	
	return 0;
}
