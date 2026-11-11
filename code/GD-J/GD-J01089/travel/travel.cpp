#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5;
string a1,a2,b1,b2,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdin);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)ans[0]='1';
	else{cout<<ans;exit(0);}
	if(a2[0]==b2[0]&&a2[1]==b2[1])ans[1]='1';
	else{cout<<ans;exit(0);}
	if((a2[0]==b2[0]&&a2[1]==b2[1])&&((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D')))ans[2]='1';
	else{cout<<ans;exit(0);}
	if((a2[0]==b2[0]&&a2[1]==b2[1])&&((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D'))
	&&((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='B')||
	(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')))ans[3]='1';
	cout<<ans;
	return 0; 
} 
