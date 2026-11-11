#include<bits/stdc++.h>
#include<string>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool f1=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	char n1=s1[0],n2=s2[0],b1=s1[1],b2=s2[1],a1=s1[2],a2=s2[2];
	if(c1==c2)cout<<1;
	else{
		cout<<0;
		f1=0;
	}
	if(n1==n2&&b1==b2&&f1==1)cout<<1;
	else{
		cout<<0;
		f1=0;
	}
	if(((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')||(a1=='A'&&a2=='C')||(a1=='D'&&a2=='E')||(a1=='B'&&a2=='A')||(a1=='C'&&a2=='B')||(a1=='C'&&a2=='A')||(a1=='E'&&a2=='D'))&&f1==1)cout<<1;
	else{
		cout<<0;
		f1=0;
	}
	if(((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')||(a1=='D'&&a2=='E')||(a1=='B'&&a2=='A')||(a1=='C'&&a2=='B')||(a1=='E'&&a2=='D'))&&f1==1)cout<<1;
	else cout<<0;
	return 0;
}
