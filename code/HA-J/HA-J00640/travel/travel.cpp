#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b==d) cout<<1;
	else cout<<0;
	if(a==c&&b==d &&((e=='F'&&f=='D')||(e=='D'&&f=='F')||(e=='C'&&(f=='B'||f=='A'))||(e=='B'&&(f=='C'||f=='A'))||(e=='A'&&(f=='B'||f=='C')))) cout<<1;
	else cout<<0;
	if(a==c&&b==d &&((e=='F'&&f=='D')||(e=='D'&&f=='F')||(e=='C'&&f=='B')||(e=='B'&&(f=='C'||f=='A'))||(e=='A'&&f=='B')))cout<<1;
	else cout<<0;
	return 0;
}
 
