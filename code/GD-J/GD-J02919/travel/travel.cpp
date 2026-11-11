#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else cout<<"0000",exit(0);
	if(s2[0]==s4[0]&&s2[1]==s4[1]) cout<<1;
	else cout<<"000",exit(0);
	if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C')) cout<<1;
	else cout<<"00",exit(0);
	n=s2[2]-s4[2];
	if(abs(n)==1) cout<<1;
	else cout<<"0",exit(0);
	return 0;
} 
