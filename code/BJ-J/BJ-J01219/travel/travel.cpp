#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int a,b;
		a=(s1[0]-'0')*10+s1[1]-'0';
		b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b){
			cout<<"1";
			char x=s1[2],y=s2[2];
			if('D'<=x&&x<='F'&&'D'<=y&&y<='F'){
				cout<<"11";
			}else if('A'<=x&&x<='C'&&'A'<=y&&y<='C'){
				cout<<"1";
				if((x=='A'&&y=='C')||(y=='A'&&x=='C')){
					cout<<"0";
				}else{
					cout<<"1";
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
