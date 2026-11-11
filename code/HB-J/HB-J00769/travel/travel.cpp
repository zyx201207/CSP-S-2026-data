#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d,x,y;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s2[2]=='D' || s2[2]=='F') x=1;
	else x=0;
	if(s4[2]=='D' || s4[2]=='F') x=1;
	else x=0;
	if(s1==s3) a=1;
	if(a && s2[0]+s2[1]==s4[0]+s4[1]) b=1;
	if(b && x==y) c=1;
	if(c && abs(s2[2]-s4[2])==1) d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
