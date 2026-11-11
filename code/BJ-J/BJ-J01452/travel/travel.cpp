#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if (a1==a3){
		cout<<1;
		if (stoi(a2)==stoi(a4)){
			cout<<1;
			if ((a2[2]<='C'&&a4[2]<='C')||(a2[2]>='D'&&a4[2]>='D')){
				cout<<1;
				if ((a2[2]=='A'&&a4[2]=='B')||(a2[2]=='B'&&a4[2]=='A')||(a2[2]=='C'&&a4[2]=='B')||(a2[2]=='B'&&a4[2]=='C')||(a2[2]=='D'&&a4[2]=='E')||(a2[2]=='E'&&a4[2]=='D')){
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
