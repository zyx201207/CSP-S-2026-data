#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a1,a2,b1,b2;
	bool flag=true;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int c1=(a2[0]-'0')*10+(a2[1]-'0');
	int c2=(b2[0]-'0')*10+(b2[1]-'0');
	if(c1==c2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char d1=a2[2],d2=b2[2];
	if((d1=='A'||d1=='B'||d1=='C')&&(d2=='D'||d2=='F')||d1==d2){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if((d1=='A'&&d2=='C')||(d1=='C'&&d2=='A'))
		cout<<0;
	else cout<<1;
	return 0;
}
