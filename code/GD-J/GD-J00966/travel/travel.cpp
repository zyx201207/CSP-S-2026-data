#include<bits/stdc++.h>
using namespace std;
string z1,z2;
long long j1,j2,p1,p2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>j1>>z1>>j2>>z2;
	p1=(z1[0]-'0')*10+(z1[1]-'0');
	p2=(z2[0]-'0')*10+(z2[1]-'0');
	if(z1[2]=='A'||z1[2]=='B'||z1[2]=='C')c1=1;
	else c1=2;
	if(z2[2]=='A'||z2[2]=='B'||z2[2]=='C')c2=1;
	else c2=2;
	if(j1!=j2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(p1!=p2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(c1!=c2){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(z1[2]-z2[2])==1)cout<<"1";
	else cout<<"0";
	
	return 0;
}
