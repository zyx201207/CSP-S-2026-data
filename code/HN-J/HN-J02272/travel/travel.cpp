#include<bits/stdc++.h>
using namespace std;
int c1,c2,k1,k2,s1,s2;
string m1,m2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m1>>m2;
	c1=(m1[0]-'0')*10+(m1[1]-'0');
	k1=m2[2]-'A';
	if(k1==3)k1=4;
	s1=(m2[0]-'0')*10+(m2[1]-'0');
	cin>>m1>>m2;
	c2=(m1[0]-'0')*10+(m1[1]-'0');
	k2=m2[2]-'A';
	if(k2==3)k2=4;
	s2=(m2[0]-'0')*10+(m2[1]-'0');
	if(c1==c2){
		cout<<'1';
		if(s1==s2){
			cout<<'1';
			if((k1>3&&k2>3)||(k1<3&&k2<3)){
				cout<<'1';
				if(abs(k1-k2)==1){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000"; 
	return 0;
} 
