#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int n1,n2;
char m1,m2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){cout<<"1";}
	else{cout<<"0000";return 0;}
	
	n1=(int)s1[1]*10+(int)s1[1];
	n2=(int)s2[1]*10+(int)s2[1];
	if(n1==n2){cout<<"1";}
	else{cout<<"000";return 0;}
	
	m1=s1[2];
	m2=s2[2];
	if(( (m1=='A' or m1=='B' or m1=='C') and (m2=='A' or m2=='B' or m2=='C') ) or ( (m1=='D' or m1=='F') and (m2=='D' or m2=='F')) ){cout<<"1";}
	else{cout<<"00";return 0;}
	
	if(   (m1=='A' and m2=='B') or (m1=='B' and m2=='C') or (m1=='D' and m2=='F') or (m2=='A' and m1=='B') or (m2=='B' and m1=='C') or (m2=='D' and m1=='F')){cout<<"1";}
	else{cout<<"0";}
	
	return 0;
}
