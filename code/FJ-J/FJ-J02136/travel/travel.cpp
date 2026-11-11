#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int l1=s1.size(),l2=s2.size();
	if(c1==c2) cout<<1;
	else cout<<0;
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	
	int t=abs(s1[l1-1]-s2[l2-1]);
	bool tt=false;
	if((s1[l1-1]>'C'&&s2[l2-1]>'C')||(s1[l1-1]<='C'&&s2[l2-1]<='C')) tt=true;
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&tt) cout<<1;
	else cout<<0;
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&tt&&t==1) cout<<1;
	else cout<<0;
	return 0;
}

