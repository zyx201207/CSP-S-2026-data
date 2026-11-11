#include<bits/stdc++.h> 
#define int long long
using namespace std;
int c1,c2;
int a1,a2,f1,f2;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1;
	cin>>c2>>s2;
	
	a1=(s1[0]-'0')*10+s1[1]-'0';
	a2=(s2[0]-'0')*10+s2[1]-'0';
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')f1=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')f2=1;
	
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2)cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2&&f1==f2)cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2&&f1==f2&&abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
