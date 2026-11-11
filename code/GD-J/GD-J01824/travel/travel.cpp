#include<bits/stdc++.h>
using namespace std;
string c,z,c2,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>z>>c2>>z2;
	if(c==c2) cout<<1;
	else {cout<<"0000";return 0;}
	if(z[0]==z2[0]&&z[1]==z2[1]) cout<<1;
	else {cout<<"000";return 0;}
	int a=int(z[2]),b=int(z2[2]);
	if(a<=67&&b<=67||a>67&&b>67)
	{
		cout<<1;
		if(abs(a-b)==1||a==68&&b==70||a==70&&b==68) cout<<1;
		else cout<<0;
	} 
	else cout<<"00";
	return 0;
} 
