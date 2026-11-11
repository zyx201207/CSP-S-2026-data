#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p1,p2;
char m1,m2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	if(p1==p2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	m1=s1[2],m2=s2[2];
	if(((m1=='A'||m1=='B'||m1=='C')&&(m2=='A'||m2=='B'||m2=='C'))||((m1=='D'||m1=='E')&&(m2=='D'||m2=='E'))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	int a=m1-'A',b=m2-'A';
	if(a>b) swap(a,b);
	if(b==a+1) cout<<1;
	else cout<<0;
	return 0;
} 
