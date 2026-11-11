#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,c2,c3,c4;
	int sf1,sf2;
	cin>>c1>>c2>>c3>>c4;
	if(c2[2]=='D'||c2[2]=='F') sf1=1;
	else sf1=0;
	if(c4[2]=='D'||c4[2]=='F') sf2=1;
	else sf2=0;
	if(c1==c3) cout<<1;
	else cout<<0;
	if(c2[0]==c4[0]&&c2[1]==c4[1]) cout<<1;
	else cout<<0;
	if((c2[0]==c4[0]&&c2[1]==c4[1])&&sf1+sf2!=1) cout<<1;
	else cout<<0;
//	cout<<'('<<sf1+sf2<<')';
	if((c2[0]==c4[0]&&c2[1]==c4[1])&&(sf1+sf2!=1)&&(c2[2]+1==c4[2]||c4[2]+1==c2[2])) cout<<1;
	else cout<<0;
	return 0;
} 
