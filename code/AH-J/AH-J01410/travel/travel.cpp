#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int za=0,zb=0;
char ha,hb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	za=(a2[0]-48)*10+a2[1]-48;
	zb=(b2[0]-48)*10+b2[1]-48;
	ha=a2[2];
	hb=b2[2];
	if(a1[0]==b1[0]&&a1[1]==b1[1]) cout<<1;
	else cout<<0;
	if(a1[0]==b1[0]&&a1[1]==b1[1]&&za==zb) cout<<1;
	else cout<<0;
	if(a1[0]==b1[0]&&a1[1]==b1[1]&&za==zb){
		if((ha>='A'&&ha<='C'&&hb>='A'&&hb<='C')||(ha=='D'&&hb=='F')||(ha=='F'&&hb=='D')) cout<<1;
		else cout<<0;
	}else cout<<0;
	if(a1[0]==b1[0]&&a1[1]==b1[1]&&za==zb){
		if(((ha>='A'&&ha<='C'&&hb>='A'&&hb<='C')||(ha=='D'&&hb=='F')||(ha=='F'&&hb=='D'))&&(char(ha+1)==hb||char(ha-1)==hb)) cout<<1;
		else cout<<0;
	}else cout<<0;

	return 0;
}

