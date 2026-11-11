#include<bits/stdc++.h>
using namespace std;
char a,b;
int a1,b1,c1,d1,a2,b2,c2,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a>>a2>>b2>>b;
	if(a1==a2){
		cout<<1;
		if(b1==b2){
			cout<<1;
			if(a!='D'&&b!='D'&&a!='E'&&b!='E'){
				cout<<1;
				if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='C'&&b=='B')||(a=='B'&&b=='C')){
				cout<<1;
				}else{
					cout<<0;
				}
			}else if((a=='D'&&b=='E')||(a=='E'&&b=='D')){
				cout<<11;
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
