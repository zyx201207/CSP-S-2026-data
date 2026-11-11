#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char a3,b3;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	if (a1==b1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if (a2==b2) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if (((a3=='A' || a3=='B' || a3=='C') && (b3=='A' || b3=='B' || b3=='C')) || ((a3=='E' || a3=='F') and (b3=='E' || b3=='F'))) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	
	if(abs(int(a3-b3))==1) cout<<1;
	else cout<<0;
	return 0;
}
