#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		int a1=(s1[0]-48)*10+s1[1]-48;
		int a2=(s2[0]-48)*10+s2[1]-48;
		if(a1!=a2)cout<<"000";
		else{
			cout<<"1";
			char b1=s1[2],b2=s2[2];
			if((b1=='D'&&b2!='F')||(b2=='D'&&b1!='F'))cout<<"00";
			else{
				cout<<"1";
				if((b1=='D'&&b2=='F')||(b1=='D'&&b2=='F')||(b1=='A'&&b2=='B')||(b1=='B'&&b2=='C')||(b1=='B'&&b2=='A')||(b1=='C'&&b2=='B'))cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
