//GZ-J00311 贵阳市第三中学 安德雯
#include<bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>rc>>rz>>xc>>xz;
    if(rc!=xc)  cout<<"0000";
    else{
        cout<<'1';
        if(rz[0]!=xz[0] || rz[1]!=xz[1])  cout<<"000";
        else{
            cout<<'1';
            if(((rz[2]=='A' || rz[2]=='B' || rz[2]=='C') && (xz[2]=='D' || xz[2]=='E')) || ((xz[2]=='A' || xz[2]=='B' || xz[2]=='C') && (rz[2]=='D' || rz[2]=='E')))  cout<<"00";
            else{
                cout<<'1';
                if(((rz[2]=='A' || rz[2]=='C') && xz[2]=='B') || (rz[2]=='B' && (xz[2]=='A' || xz[2]=='C')) || (rz[2]=='D' && xz[2]=='E') || (rz[2]=='E' && xz[2]=='D'))  cout<<'1';
                else  cout<<'0';
            }
        }
    }
	return 0;
}
