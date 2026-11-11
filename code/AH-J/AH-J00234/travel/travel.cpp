#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2) ans+='1';
	else{
		cout<<"0000";
		return 0;
	}
	if(b1[0]*10+b1[1]==b2[0]*10+b2[1]) ans+='1';
	else{
		cout<<"1000";
		return 0;
	}
	if(b1[2]+b2[2]=='A'+'B'||b1[2]+b2[2]=='C'+'B'||b1[2]+b2[2]=='A'+'C'||b1[2]+b2[2]=='F'+'D') ans+='1';
	else{
		cout<<"1100";
		return 0;
	}
	if(b2[2]-b1[2]==1||b1[2]-b2[2]==1) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
