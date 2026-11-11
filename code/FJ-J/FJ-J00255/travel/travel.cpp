#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool a,b,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0] && a1[1]==b1[1]) a=true;//////////////////////////////////////////////
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0] && a2[1]==b2[1]) b=true;
	else{
		cout<<"1000";
		return 0;
	}
	if(a2[2]<='C' && b2[2]<='C' || a2[2]>='D' && b2[2]>='D') c=true;
	else{
		cout<<"1100";
		return 0;
	}
	if(a2[2]+1==b2[2] || b2[2]+1==a2[2]) cout<<"1111";
	else cout<<"1110";
	return 0;
}