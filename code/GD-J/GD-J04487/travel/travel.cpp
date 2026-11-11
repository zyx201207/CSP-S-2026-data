#include<bits/stdc++.h>
#define ll long long
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define itn int
#define asn ans
using namespace std;
string c1,c2,s1,s2;
int main()
{
	fre("travel");
	cin>>c1>>s1>>c2>>s2;
	cin.tie(nullptr);
	if(c1==c2)cout<<1;
	else{cout<<"0000";return 0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else{cout<<"000";return 0;}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]<='F'&&s1[2]>'C'&&s2[2]<='F'&&s2[2]>'C'))cout<<1;
	else{cout<<"00";return 0;}
	if(s1[2]==s2[2]-1||s1[2]==s2[2]+1)cout<<1;
	else{cout<<"0";return 0;}
	return 0;
}
