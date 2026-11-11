#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r,rz,x,xz;
    cin>>r>>rz>>x>>xz;
    string ans;
    if(r==x)
    {
        ans+="1";
    }else{
        ans+="0";
    }
    if(rz[0]==xz[0]&&rz[1]==xz[1])
    {
        ans+="1";
    }else{
        ans+="0";
    }
    if((rz[2]=='A'||rz[2]=='B'||rz[2]=='C')&&(xz[2]=='A'||xz[2]=='B'||xz[2]=='C')
       ||(rz[2]=='D'||rz[2]=='F')&&(xz[2]=='D'||xz[2]=='F'))
    {
        ans+="1";
    }else{
        ans+="0";
    }
    if(rz[2]+1==xz[2]||rz[2]-1==xz[2])
    {
        ans+="1";
    }else{
        ans+="0";
    }
    cout<<ans;
    return 0;
}
