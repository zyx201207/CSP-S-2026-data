#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0000",exit(0);
	if((s1[0]==s2[0])&&(s1[1]==s2[1])) cout<<"1";
	else cout<<"000",exit(0);
	int p1=0,p2=0;
	if((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C')) p1=1;
	else p1=2;
	if((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C')) p2=1;
	else p2=2;	
	if(p1==p2) cout<<"1";
	else cout<<"00",exit(0);
	if(s1[2]>s2[2]) swap(s1,s2);
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
