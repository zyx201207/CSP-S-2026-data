#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a1,b1;
char a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[0]+s1[1];
	b1=s2[0]+s2[1];
	a2=s1[2];
	b2=s2[2];
	if(c1==c2){
		cout<<"1";
		if(a1==b1){
			cout<<"1";
			if((int(a2-'A')<3&&int(b2-'A')<3)||(int(a2-'A')>=3&&int(b2-'A')>=3)){
				cout<<"1"; 
				if(abs(int(a2)-int(b2))==1){
					cout<<"1";
				}else{
					cout<<"0";
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
