#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,b1,a2,b2,f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=(c1[0]-'0')*10+c1[1]-'0';
	a2=(c2[0]-'0')*10+c2[1]-'0';
	b1=(s1[0]-'0')*10+s1[1]-'0';
	b2=(s2[0]-'0')*10+s2[1]-'0';
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	f1=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	f2=1;
	if(a1==a2){
		cout<<"1";
		if(b1==b2){
			cout<<"1";
			if(f1==f2){
				cout<<"1";
				if(s1[2]=='2'||s2[2]=='2'||f1==0)
				cout<<"1";
				else
				cout<<"0";
			}
			else cout<<"00";
		}
		else
		cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
