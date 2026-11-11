#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	frexp('travel.in','r',stdin);
	frexp('travel.out','w',stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=(s1[0]-'0')*10+s1[1]-'0';
	int a2=(s2[0]-'0')*10+s2[1]-'0';
	char b1=s1[2];
	char b2=s2[2];
	if(c1==c2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if(b1<='C'&&b2<='C'||b1>'C'&&b2>'C'){
				cout<<1;
				if(b1!='C'&&b2!='C'&&abs(b1-b2)==1)
					cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
