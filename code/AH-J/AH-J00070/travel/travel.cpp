#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ct continue
const ll N=1e5+5,inf=1e18;
ll c1,c2,c3,c4,s3,s4;
string s1,s2;
void solve(){
	if(s1[2]=='A')s3=1;
	if(s1[2]=='B')s3=2;
	if(s1[2]=='C')s3=3;
	if(s1[2]=='D')s3=4;
	if(s1[2]=='E')s3=5;
	
	if(s2[2]=='A')s4=1;
	if(s2[2]=='B')s4=2;
	if(s2[2]=='C')s4=3;
	if(s2[2]=='D')s4=4;
	if(s2[2]=='E')s4=5;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	solve();
	c3=(s1[0]-'0')*10+(s1[1]-'0');
	c4=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2)cout<<1;
	else {cout<<0<<0<<0<<0;return 0;}
	if(c3==c4)cout<<1;
	else {cout<<0<<0<<0;return 0;}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))cout<<1;
	else {cout<<0<<0;return 0;}
	if(s3-1==s4||s3+1==s4)cout<<1;
	else cout<<0;
    return 0;
}
