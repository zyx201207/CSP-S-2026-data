#include<bits/stdc++.h>
using namespace std;
string a1,a2,d1,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a1>>d1>>a2>>d2;
	if(a1==a2){
		cout<<'1';
		if(d1[1]==d2[1]){
			cout<<'1';
			if((d1[2]>='A'&&d1[2]<='C'&&d2[2]>='A'&&d2[2]<='C')||(d1[2]>='D'&&d1[2]<='F'&&d2[2]>='D'&&d2[2]<='F')){
				cout<<'1';
				if((d1[2]>='A'&&d1[2]<='B'&&d2[2]>='A'&&d2[2]<='B')||(d1[2]>='D'&&d1[2]<='F'&&d2[2]>='D'&&d2[2]<='F')||(d1[2]>='B'&&d1[2]<='C'&&d2[2]>='B'&&d2[2]<='C')){
					cout<<'1';
				}else{
					cout<<"0";
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
