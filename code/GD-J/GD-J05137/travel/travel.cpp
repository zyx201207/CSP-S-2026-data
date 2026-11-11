#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,k1,k2;char a1,b1;int s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<"1";
		k1=s1.substr(0,2);
		k2=s2.substr(0,2);
		if (k1==k2){
			cout<<"1";
			a1=s1[2];b1=s2[2];
			if (((a1=='A' || a1=='B' || a1=='C') && (b1=='A' || b1=='B' || b1=='C')) || ((a1=='D' || a1=='F') && (b1=='D' || b1=='F'))){
				cout<<"1";
				if (abs(a1-b1)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
