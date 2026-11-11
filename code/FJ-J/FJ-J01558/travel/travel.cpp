#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,zw1,zw2;
int a,b,c,d,ans=0;
char hh1,hh2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	a=int(cx1[0]-'0')*10+int(cx1[1]-'0');
	c=int(cx2[0]-'0')*10+int(cx2[1]-'0');
	if(a==c) {
		ans++;
		cout<<1;
	} else {
		cout<<0;
	}
	b=int(zw1[0]-'0')*10+int(zw1[1]-'0');
	d=int(zw2[0]-'0')*10+int(zw2[1]-'0');
	if(b==d&&ans==1) {
		ans++;
		cout<<1;
	} else {
		cout<<0;
	}
	hh1=zw1[2];
	hh2=zw2[2];
	if(ans==2&&(hh1=='A'&&hh2=='B'||hh1=='A'&&hh2=='C'||hh1=='B'&&hh2=='A'||hh1=='B'&&hh2=='C'||hh1=='C'&&hh2=='A'||hh1=='C'&&hh2=='B'||hh1=='D'&&hh2=='F'||hh1=='F'&&hh2=='D')) {
	ans++;
	cout<<1;
	} else {
		cout<<0;
	}
	if(ans==3&&(hh1=='A'&&hh2=='B'||hh1=='B'&&hh2=='A'||hh1=='B'&&hh2=='C'||hh1=='C'&&hh2=='B'||hh1=='D'&&hh2=='F'||hh1=='F'&&hh2=='D')) {
		cout<<1;
	} else {
		cout<<0;
	}
	return 0;
}
