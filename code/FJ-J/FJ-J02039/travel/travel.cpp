#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a,b,x,y;
	char r,l;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	x=(c2[0]-'0')*10+(c2[1]-'0');
	b=(s1[0]-'0')*10+(s1[1]-'0');
	y=(s2[0]-'0')*10+(s2[1]-'0');
	r=s1[2];
	l=s2[2];
	if(a==x)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(b==y)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	} 
	if((r<='C'&&l>='D')||(r>='D'&&l<='C')){
		cout<<0<<0;
		return 0;
	}
	else cout<<1;
	if(r=='A'&&l=='B'||r=='B'&&l=='A'||r=='B'&&l=='C'||r=='C'&&l=='B'||r=='D'&&l=='E'||r=='E'&&l=='D')cout<<1;
	else cout<<0;
	return 0;
}
