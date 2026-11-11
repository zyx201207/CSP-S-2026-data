#include<bits/stdc++.h>
using namespace std;
string s1,s2,z1,z2;
int cx1,cx2,zw1,zw2;
char a1,a2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>z1>>s2>>z2;
	int len=s1.length();
	for(int i=0;i<len;i++) cx1=cx1*10+(s1[i]-'0');
	len=s2.length();
	for(int i=0;i<len;i++) cx2=cx2*10+(s2[i]-'0');
	if(cx1!=cx2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	
	len=z1.length();
	for(int i=0;i<len-1;i++) zw1=zw1*10+(z1[i]-'0');
	len=z2.length();
	for(int i=0;i<len-1;i++) zw2=zw2*10+(z2[i]-'0');
	if(zw1!=zw2) {
		cout<<"000";
		return 0;
	}
	cout<<"1";
	
	len=z1.length();
	a1=z1[len-1];
	len=z2.length();
	a2=z2[len-1];
	if(a1=='D' && a2=='E') {
		cout<<"11";
		return 0;
	}
	if(a1=='E' && a2=='D') {
		cout<<"11";
		return 0;
	}
	if(a1=='A' && a2=='B') {
		cout<<"11";
		return 0;
	}
	if(a1=='B' && a2=='A') {
		cout<<"11";
		return 0;
	}
	if(a1=='B' && a2=='C') {
		cout<<"11";
		return 0;
	}
	if(a1=='C' && a2=='B') {
		cout<<"11";
		return 0;
	}
	if(a1=='A' && a2=='C') {
		cout<<"10";
		return 0;
	}
	if(a1=='C' && a2=='A') {
		cout<<"10";
		return 0;
	}
	cout<<"00";
}
