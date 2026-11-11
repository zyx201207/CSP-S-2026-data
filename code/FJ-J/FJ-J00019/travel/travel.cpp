#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool r=c1==c2,r1=s1[0]+s1[1]==s2[0]+s2[1];
	if(r) cout<<"1";
	else cout<<"0";
	if(r&&r1) cout<<"1";
	else cout<<"0";
	bool t=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'),t2=(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F');
	bool r2=t||t2;
	if(r&&r1&&r2) cout<<"1";
	else cout<<"0";
	bool r3=abs(s1[2]-s2[2])==1;
	if(r&&r1&&r2&&r3) cout<<"1";
	else cout<<"0";
	return 0; 
} 
