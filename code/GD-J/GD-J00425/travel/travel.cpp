#include<bits/stdc++.h>
using namespace std;
int a,b;
bool flag;
string s,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>l;
	if(a==b) cout<<1;
	else return cout<<"0000\n",0;
	if(s[1]==l[1]&&s[0]==l[0]) cout<<1;
	else return cout<<"000\n",0;
	if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(l[2]=='A'||l[2]=='B'||l[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(l[2]=='D'||l[2]=='F')))cout<<1;
	else return cout<<"00\n",0;
	if((s[2]=='A'&&l[2]=='B')||(l[2]=='A'&&s[2]=='B')||(s[2]=='B'&&l[2]=='C')||(s[2]=='C'&&l[2]=='B')||(s[2]=='D'&&l[2]=='F'||(s[2]=='F'&&l[2]=='D'))) cout<<1<<"\n";
	else cout<<0<<"\n";
	return 0;
} 
