#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a1,a2;
char b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		a1=s1.substr(0,2);
		a2=s2.substr(0,2);
		if(a1==a2){
			cout<<"1";
			b1=s1[2];
			b2=s2[2];
			if(b1>='A'&&b1<='C'){
				if(b2>='D'&&b2<='F')
					cout<<"00";
				else{
					cout<<"1";
					if(b1-b2==1||b2-b1==1)
						cout<<"1";
					else
						cout<<"0";
				}
			}
			else{
				if(b2>='A'&&b2<='C')
					cout<<"00";
				else{
					cout<<"1";
					if(b1-b2==1||b2-b1==1)
						cout<<"1";
					else
						cout<<"0";
				}
			}
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
