#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b && (a1[0]==b1[0]&&a1[1]==b1[1]) && (((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'))||((a1[2]=='C'||a1[2]=='D')&&(b1[2]=='C'||b1[2]=='D')) && abs(a1[2]-b1[2])==1)cout<<"1111";
    else if(a==b && (a1[0]==b1[0]&&a1[1]==b1[1]) && (((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'))||((a1[2]=='C'||a1[2]=='D')&&(b1[2]=='C'||b1[2]=='D')))cout<<"1110";
    else if(a==b && (a1[0]==b1[0]&&a1[1]==b1[1]))cout<<"1100";
    else if(a==b)cout<<"1000";
    else cout<<"0000"
	return 0;
}
