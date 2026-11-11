#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int a1,b1,a2,b2;
		int d1,d2;
		a1=s1[0];
		b1=s1[1];
		a2=s2[0];
		b2=s2[1];
		d1=s1[2];
		d2=s2[2];
		if(a1==a2&&b1==b2){
			cout<<1;
			if(max(d1,d2)<'D'||min(d1,d2)>'C'){
				cout<<1;
				if(max(d1,d2)<'D'&&min(d1,d2)+1==max(d1,d2)){
					cout<<1;
				}else if(min(d1,d2)>'C'){
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
