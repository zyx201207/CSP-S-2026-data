#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2;
string z1,z2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1!=c2) {cout<<"0000";return 0;}
	else cout<<1;
	int k;
	if(z1[0]==z2[0]&&z1[1]==z2[1]) cout<<1,k=1;
	else cout<<0,k=0;
	if(k==0) cout<<0;
	else
	{
		k=0;
		if((z1[2]=='D'&&z2[2]=='F')||(z1[2]=='F'&&z2[2]=='D')) cout<<1,k=1;
		if(z1[2]=='A'&&z2[2]=='B') cout<<1,k=1;
		if(z1[2]=='A'&&z2[2]=='C') cout<<1,k=1;
		if(z1[2]=='B'&&z2[2]=='A') cout<<1,k=1;
		if(z1[2]=='B'&&z2[2]=='C') cout<<1,k=1;
		if(z1[2]=='C'&&z2[2]=='B') cout<<1,k=1;
		if(z1[2]=='C'&&z2[2]=='A') cout<<1,k=1;
	}
	if(k==0) cout<<0;
	else
	{
		k=0;
		if((z1[2]=='D'&&z2[2]=='F')||(z1[2]=='F'&&z2[2]=='D')) cout<<1,k=1;
		if(z1[2]=='A'&&z2[2]=='B') cout<<1,k=1;
		if(z1[2]=='B'&&(z2[2]=='A'||z2[2]=='C')) cout<<1,k=1;
		if(z1[2]=='C'&&z2[2]=='B') cout<<1,k=1;
		if(k==0) cout<<0;
	}
	return 0;
}
