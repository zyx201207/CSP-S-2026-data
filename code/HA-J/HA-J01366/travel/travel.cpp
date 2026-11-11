#include<bits/stdc++.h>
using namespace std;
int cc1,cc2,pai1,pai2,paiid1,paiid2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>s1>>cc2>>s2;
	if(cc1==cc2)
		cout<<1;
	else
		cout<<0;
	
	pai1=s1[0]-'0';
	pai1=pai1*10+s1[1]-'0';
	
	pai2=s2[0]-'0';
	pai2=pai2*10+s2[1]-'0';
	
	if(s1[2]=='A')
		paiid1=1;
	else if(s1[2]=='B')
		paiid1=2;
	else if(s1[2]=='C')
		paiid1=3;
	else if(s1[2]=='D')
		paiid1=-1;
	else if(s1[2]=='F')
		paiid1=-2;
	
	if(s2[2]=='A')
		paiid2=1;
	else if(s2[2]=='B')
		paiid2=2;
	else if(s2[2]=='C')
		paiid2=3;
	else if(s2[2]=='D')
		paiid2=-1;
	else if(s2[2]=='F')
		paiid2=-2;
	
	if(cc1==cc2&&pai1==pai2)
		cout<<1;
	else
		cout<<0;
	if(cc1==cc2&&pai1==pai2&&((paiid1<0&&paiid2<0)||(paiid1>0&&paiid2>0)))
		cout<<1;
	else
		cout<<0;
	if(cc1==cc2&&pai1==pai2&&((paiid1+1==paiid2)||(paiid1-1==paiid2)))
		cout<<1;
	else
		cout<<0;
	return 0;
}
