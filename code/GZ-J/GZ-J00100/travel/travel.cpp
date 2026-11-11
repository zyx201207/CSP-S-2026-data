//ÌÆÎÄ²©  GZ-J00100
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	long long n,m;
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m) cout<<1; else {cout<<"0000"; return 0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1; else {cout<<"000";return 0;}
	if((s1[2]>='A'&&s1[2]<='C' && s2[2]>='A'&&s2[2]<='C' )|| (s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s2[2]=='F') )cout<<1; else {cout<<"00";return 0;}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s2[2]=='F') )cout<<1;
	else{
		int s1l=int(s1[2]),s2l=int(s2[2]),c=abs(s1l-s2l);
		if(c==1) cout<<1; else cout<<0;
	}
} 
