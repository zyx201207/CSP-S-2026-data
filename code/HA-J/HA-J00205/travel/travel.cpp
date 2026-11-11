#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0] && a2[1]==b2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((('A'<=a2[2] && a2[2]<='C') && ('A'<=b2[2] && b2[2]<='C')) || (('D'<=a2[2] && a2[2]<='F') && ('D'<=b2[2] && b2[2]<='F'))) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if((a2[2]=='D' && b2[2]=='F') || (a2[2]=='F' && b2[2]=='D')){
		cout<<"1";
		return 0;
	}
	if((a2[2]>b2[2] && a2[2]-1==b2[2]) || (a2[2]<b2[2] && a2[2]+1==b2[2])) cout<<"1";
	else cout<<"0";
	return 0;
}

