#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	a1+=s1[0]-'0';
	a1+=s1[1]-'0';
	a2+=s2[0]-'0';
	a2+=s2[1]-'0';
	b1+=s1[2]-'A'+1;
	b2+=s2[2]-'A'+1;
	if(c1==c2 && a1==a2) cout<<1;
	else cout<<0;
	
	if(c1==c2 && a1==a2 && ((b1<=3 && b2<=3) || (b1==4 && b2==5) || (b1==5 && b2==4)) )
		cout<<1;
	else cout<<0;
	if(c1==c2 && a1==a2 && ((b1==1 && b2==2) || (b1==2 && b2==1) || 
	(b1==2 && b1==3) || (b1==3 && b1==2) ||
	(b1==4 && b2==5) || (b1==5 && b2==4) ))
		cout<<1;
	else cout<<0;
	return 0;
} 
