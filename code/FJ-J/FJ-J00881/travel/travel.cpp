#include<bits/stdc++.h>
using namespace std;
char a1,a2,a3;
int b1,b2,b3,b4,c1,c2;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin>>b1>>b2>>a1>>a2>>b3>>b4>>a3;
	c1=a1-'A';
	c2=a3-'A';
	if(b1==b3){
		cout<<1;
		if(b2==b4){
			cout<<1;
			if(c1<3&&c2<3){
				cout<<1;
				if(c1==1||c2==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
			if(c1>2&&c2>2){
				cout<<"11";
			}
			if((c1>2&&c2<3)||(c1<3&&c2>2)){
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
