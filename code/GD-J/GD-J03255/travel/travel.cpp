#include<bits/stdc++.h>
using namespace std;
int gat1,gat2,l1,l2,seat1,seat2;
string g1,g2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>g1>>s1>>g2>>s2;
	gat1=(g1[0]-'0')*10+(g1[1]-'0');
	gat2=(g2[0]-'0')*10+(g2[1]-'0');
	l1=(s1[0]-'0')*10+(s1[1]-'0');
	l2=(s2[0]-'0')*10+(s2[1]-'0');
	seat1=s1[2]-'A'+1;
	seat2=s2[2]-'A'+1;
	if(gat1==gat2) cout<<1;
	else cout<<0;
	if(gat1==gat2&&l1==l2) cout<<1;
	else cout<<0;
	if(gat1==gat2&&l1==l2&&((seat1<=3&&seat2<=3)||(seat1>3&&seat2>3))) cout<<1;
	else cout<<0;
	if(gat1==gat2&&l1==l2&&abs(seat1-seat2)==1&&((seat1<=3&&seat2<=3)||(seat1>3&&seat2>3))) cout<<1;
	else cout<<0;
	return 0;
} 
