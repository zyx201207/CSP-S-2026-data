#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,cc;
bool cx,p,ce,l;
string s,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		
		cx=1;
	}
	if(cx&&s[0]==ss[0]&&s[1]==ss[1]){
		p=1;
	}
	if(cx&&p&&((s[2]<='C'&&ss[2]<='C')||(s[2]>='D'&&ss[2]>='D'))){
		ce=1;
		if(cx&&p&&((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&(ss[2]=='A'||ss[2]=='C'))||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D'))){
			l=1;
		}
	}
	cout<<cx<<p<<ce<<l;
	return 0;
}

