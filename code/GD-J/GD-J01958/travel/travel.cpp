#include<bits/stdc++.h>
using namespace std;
int r1,r2,k1,k2;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	r1=(s1[0]-'0')*10+(s1[1]-'0'),k1=s1[2]-'A';
	r2=(s2[0]-'0')*10+(s2[1]-'0'),k2=s2[2]-'A';
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(r1==r2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(k1<3&&k2<3||k2>2&&k1>2)cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(k1-k2)==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
