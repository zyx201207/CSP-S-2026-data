#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)cout<<1;
    else {
		cout<<"0000";
		return 0;
	}
    if(b[0]==d[0]&&b[1]==d[1])cout<<1;
    else {
		cout<<"000";
		return 0;
	}
    int cnt=0;
    if(b[2]=='A'&&d[2]=='C')cout<<10;
    else cnt++;
    if(b[2]=='B'&&d[2]=='C')cout<<11;
    else cnt++;
    if(b[2]=='A'&&d[2]=='B')cout<<11;
    else cnt++;
    if(b[2]=='B'&&d[2]=='A')cout<<11;
    else cnt++;
    if(b[2]=='C'&&d[2]=='B')cout<<11;
    else cnt++;
    if(b[2]=='C'&&d[2]=='A')cout<<10;
    else cnt++;
	if(b[2]=='F'&&d[2]=='G')cout<<11;
	else cnt++;
	if(b[2]=='G'&&d[2]=='F')cout<<11;
    else cnt++;
    if(cnt==8)cout<<"00";
    return 0;
}
