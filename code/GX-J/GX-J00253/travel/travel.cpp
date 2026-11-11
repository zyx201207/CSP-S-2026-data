#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n1,n2,m1,m2;
	cin >>n1>>n2>>m1>>m2;
	if(n1==m1)cout<<1;
	else cout<<"0000";return 0;
	for(int i=0;i<=2;i++){
		if(n1[i]==b1[i])cout<<"1";
		else cout<<"000";return 0;
	}
	if(n2[3]=='A'&&n2[3]=='B'&&n2[3]=='C'||m2[3]=='A'&&m2[3]=='B'&&m2[3]=='C')cout<<"1";
	else if(n2[3]=='D'&&n2[3]=='F'||m2[3]=='D'&&m2[3]=='F')cout<<1;
	else cout<<"00";return 0;
	if(n2[3]=='A'||m2[3]=='B'&&n2[3]=='B'||m2[3]=='C'&&n2[3]=='D'||m2[3]=='F')cout<<"1";
	else cout<<0;
	return 0;
}
