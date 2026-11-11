#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3,ss;
	cin>>s>>s1>>s2>>s3;
	if(s==s2) cout<<1;
	else cout<<0;
	if(s==s2&&s1[0]==s3[0]&&s1[1]==s3[1]) cout<<1;
	else cout<<0;
	if(s==s2&&s1[0]==s3[0]&&s1[1]==s3[1]&&((s1[2]>='A'&&s1[2]<='C'&&s3[2]>='A'&&s3[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s3[2]>='D'&&s3[2]<='F'))) cout<<1;
	else cout<<0;
	if(s==s2&&s1[0]==s3[0]&&s1[1]==s3[1]&&(s1[2]=='A'&&s3[2]=='B'||(s1[2]=='B'&&s3[2]=='A'||s1[2]=='B'&&s3[2]=='C')||(s1[2]=='D'&&s3[2]=='F'||s1[2]=='F'&&s3[2]=='D'))) cout<<1;
	else cout<<0;
	return 0;
}
