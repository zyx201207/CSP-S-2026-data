#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>s1>>m>>s2;
	if(n==m)cout<<1;
	else{cout<<"0000";return 0;}
	a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b)cout<<1;
	else {cout<<"000";return 0;}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))cout<<1;
	else{cout<<"00";return 0;}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C' ))cout<<1;
	else cout<<0;
}
