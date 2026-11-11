#include <bits/stdc++.h> 
using namespace std;
string a1,b1,a2,b2;
int t=0,p=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
    if(a1[0]==a2[0] && a1[1]==a2[1] ) cout<<1;
	else cout<<0;
	//
	if(b1[0]==b2[0] && b1[1]==b2[1] ) cout<<1;
	else cout<<0;
	//
    if(b1[2]=='A' || b1[2]=='B'|| b1[2]=='C') t=1;
    else p=1;
    if(b2[2]=='A' || b2[2]=='B'|| b2[2]=='C')
    {
    	t=1;
    	p=0;
	}
    else{
    	p=1;
    	t=0;
	};
	if(t==1 || p==1) cout<<1;
	else {
		cout<<0<<0;
		return 0;
	}
	if(b1[2]==b2[2]+'1'||b1[2]==b2[2]-'1') cout<<1;
	else cout<<0;
	
	
	
	
	
	return 0;
} 
