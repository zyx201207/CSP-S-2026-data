#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r,rz,x,xz;
    cin>>r>>rz>>x>>xz;
    int b[5]={0};
    if(r==x) b[0]=1;
    if(b[0]!=1){
        for(int i=0;i<4;i++) cout<<b[i];
        return 0;
    }
    if(rz[0]==xz[0]&&rz[1]==xz[1]) b[1]=1;
    if(b[1]!=1){
        for(int i=0;i<4;i++) cout<<b[i];
        return 0;
    }
    if(rz[2]-'A'<=2&&xz[2]-'A'<=2) b[2]=1;
    else if(rz[2]-'A'>3&&xz[2]-'A'>3) b[2]=1;
    if(rz[2]-xz[2]==1||xz[2]-rz[2]==1) b[3]=1;
    if(rz[2]=='C'||xz[2]=='C'&&rz[2]=='D'||xz[2]=='D') b[3]=0;
    for(int i=0;i<4;i++) cout<<b[i];
    cout<<endl;
    return 0;
}
