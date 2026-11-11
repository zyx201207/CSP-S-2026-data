#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2;
	cin>>c1>>a[10]>>c2>>b[10];
	if(c1==c2){
		cout<<"1";
		if(a[1]==b[1]){
			cout<<"1";
				if((a[2]!='C'&&b[2]!='D')||(a[2]!='D'&&b[2]!='C')){
					cout<<"1";
					if((a[2]=='A'&&b[2]=='C')||(a[2]=='C'&&b[2]=='A')){
						cout<<"0";
						}else{
							cout<<"1";
						}
					}
				}
	}else{
		cout<<"0000";
	}
	return 0;
}
