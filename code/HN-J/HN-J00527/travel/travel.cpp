#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	if(a[0]==a[2]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int s1=0,s2=0;
	s1+=a[1][0]-48*10;
	s1+=a[1][1]-48;
	s2+=a[3][0]-48*10;
	s2+=a[3][1]-48;
	int a1=s1;
	int a2=s2;
	if(a1==a2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((((a[1][2]=='A'||a[1][2]=='B')||a[1][2]=='C')&&(a[3][2]=='A'||(a[3][2]=='B'||a[3][2]=='C')))||(((a[1][2]=='D'||a[1][2]=='F'))&&(a[3][2]=='F'||a[3][2]=='D'))){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(((a[1][2]=='A'&&a[3][2]=='B')||(a[1][2]=='B'&&a[3][2]=='A')||(a[1][2]=='C'&&a[3][2]=='B')||(a[1][2]=='B'&&a[3][2]=='C'))||(a[1][2]=='F'&&a[3][2]=='D')||(a[1][2]=='D'&&a[3][2]=='F')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
