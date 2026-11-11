#include<bits/stdc++.h>
using namespace std;
int ci1,ci2;
string si1,si2;
bool a=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ci1>>si1>>ci2>>si2;
	if (ci1==ci2) cout<<1;
	else {
		a=0;
		cout<<0;
	}
	if (si1[0]==si2[0] && si1[1]==si2[1] && a) cout<<1;
	else {
		a=0;
		cout<<0;
	}
	if (((si1[2]>'C' && si2[2]>'C') || (si1[2]<='C' && si2[2]<='C')) && a) cout<<1;
	else {
		a=0;
		cout<<0;
	}
	if (abs(si1[2]-si2[2])==1 && a) cout<<1;
	else cout<<0;
	return 0;
} 
