#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	string a3,b3;
	a3=a2.substr(0,2);
	b3=b2.substr(0,2);
	if (a1==b1){
		cout<<1;
		if (a3==b3){
			cout<<"1";
			if(a2[2]<'D'==b2[2]<'D') {
				cout<<"1";
				if(a2[2]+1==b2[2]|| a2[2]-1==b2[2]) cout<<"1";	
				else cout<<"0";
				}
			else cout<<"00";
		
		}
		
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}