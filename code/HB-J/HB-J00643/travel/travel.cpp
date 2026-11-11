#include<bits/stdc++.h>
using namespace std;
string s,t;
string s1,t1;
char a[4]={'0','0','0','0'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s>>s1>>t>>t1;
    if(s==t) a[0]='1';
    if(s1[0]==t1[0] && s1[1]==t1[1] && a[0]=='1') a[1]='1';
    if(((s1[2]<='C' && t1[2]<='C') || (s1[2]>'C' && t1[2]>'C')) && a[1]=='1') a[2]='1';
    if(((s1[2]=='A' && t1[2]=='B') || (s1[2]=='B' && t1[2]=='C') || (s1[2]=='D' && t1[2]=='E') || (s1[2]=='B' && t1[2]=='A') || (s1[2]=='C' && t1[2]=='B') || (s1[2]=='E' && t1[2]=='D')) && a[2]=='1') a[3]='1';
    for(int i=0;i<4;i++) cout<<a[i];
    return 0;
}
