#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char r=s1[2],x=s2[2];
			if((min(r,x)=='A'&&max(r,x)=='B')||(min(r,x)=='B'&&max(r,x)=='C')||(min(r,x)=='D'&&max(r,x)=='F')){
				cout<<"11";
			}
			else if(min(r,x)=='A'&&max(r,x)=='C'){
				cout<<"10";
			}
			else{
				cout<<"00";
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
