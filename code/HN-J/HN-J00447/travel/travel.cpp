#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		a1=s1[0]+s1[1];
		a2=s2[0]+s2[1];
		if(a1!=a2){
			cout<<"000";
		}else{
			cout<<"1";
			char a11=s1[2];
			char a22=s2[2];
			if((a11<='C'&&a22>='D')||(a22<='C'&&a11>='D')){
				cout<<"00";
			}else{
				cout<<"1";
				if((abs(a11-a22)!=1)||((a1=="C"&&a2=="D")||(a2=="C"&&a1=="D"))){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
}
