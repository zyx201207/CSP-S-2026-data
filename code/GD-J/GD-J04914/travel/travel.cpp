#include<bits/stdc++.h>
using namespace std;
string s,ss,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>sa>>ss>>sb;
	if(s==ss)cout<<1;
	else cout<<"0000",exit(0);
	if(sa[1]==sb[1])cout<<1;
	else cout<<"000",exit(0);
	if(sa[2]=='D'||sa[2]=='F'){
		if(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')cout<<"00",exit(0);
		else cout<<1;
	}
	else if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C'){
		if(sb[2]=='D'||sb[2]=='F')cout<<"00",exit(0);
		else cout<<1;
	}
	if(char(sa[2]+1)==sb[2]||char(sb[2]+1)==sa[2])cout<<1;
	else cout<<0;
} 
