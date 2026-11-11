#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<'1';
			int x=s1[2],y=s2[2];
			if((x<='C'&&y<='C')||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
				cout<<'1';
				if((x=='A'&&y=='C')||(x=='C'&&y=='A')){
					cout<<'0';
				}else{
					cout<<'1';
				}
			}else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		} 
	}else{
		cout<<"0000";
	} 
	return 0;
}
