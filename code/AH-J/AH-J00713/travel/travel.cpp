#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else if(b[0]!=d[0]||b[1]!=d[1])cout<<"1000";
	else if((b[2]<='C'&&d[2]>'C')||(b[2]>'C'&&d[2]<='C'))cout<<"1100";
	else if((max(b[2],d[2])<'D'&&(b[2]+1==d[2]||b[2]-1==d[2])||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')))cout<<"1111";
	else cout<<"1110";
	return 0;
}
