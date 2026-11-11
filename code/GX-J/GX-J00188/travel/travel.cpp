#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int ans[4]={0,0,0,0};
    cin>>a>>b>>c>>d;
    if(a==c) ans[0]=1;
    else ans[0]=0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]) ans[1]=1;
    else ans[1]=0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')||(b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))) ans[2]=1;
    else ans[2]=0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]+1==d[2]||b[2]-1==d[2])||(b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')&&(b[2]+2==d[2]||b[2]-2==d[2]))) ans[3]=1;
    else ans[3]=0;
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}

