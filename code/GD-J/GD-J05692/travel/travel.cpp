#include <bits/stdc++.h>
using namespace std;



int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char pand[6][10]={};
	for(int i=1;i<=4;i++)cin>>pand[i];
	if(pand[1][0]==pand[3][0] && pand[1][1]==pand[3][1]) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(pand[2][0]==pand[4][0] && pand[2][1]==pand[4][1]) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((pand[2][2]<='C' && pand[4][2] <= 'C')||(pand[2][2]>='D' && pand[4][2] >= 'D')) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(abs(int(pand[2][2]-pand[4][2]) )<= 1) cout<<1;
	else {
		cout<<"0";
		return 0;
	}
	
	return 0;
 } 
