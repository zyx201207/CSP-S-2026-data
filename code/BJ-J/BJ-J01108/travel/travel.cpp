#include<bits/stdc++.h>
using namespace std;

int r,x;
char rr[3],xx[3];

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>r;
    cin>>rr;
    cin>>x;
    cin>>xx;
    int ri,xi;
    if(rr[2]=='A'||rr[2]=='B'||rr[2]=='C') ri=0;
    else ri=1;
    if(xx[2]=='A'||xx[2]=='B'||xx[2]=='C') xi=0;
    else xi=1;
    if(r!=x){
        cout<<"0000";
        return 0;
    }else cout<<"1";
    if(rr[0]!=xx[0]||rr[1]!=xx[1]){
        cout<<"000";
        return 0;
    }else cout<<"1";
    if(ri!=xi){
        cout<<"00";
        return 0;
    }else{
        cout<<"1";
    }
    if(rr[2]==xx[2]+1||rr[2]==xx[2]-1) cout<<"1";
    else cout<<"0";

    return 0;
}
