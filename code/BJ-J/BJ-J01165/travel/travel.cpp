#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string ca,cb,cc,cd;
    cin>>ca>>cb>>cc>>cd;
    int aa=0,ab=0,ac=0,ad=0;
    if((ca[0]==cc[0])&&(ca[1]==cc[1])){
        aa=1;
    }else{
        cout<<aa<<ab<<ac<<ad;
        return 0;
    }
    if((cb[0]==cd[0])&&(cb[1]==cd[1])){
        ab=1;
    }else{
        cout<<aa<<ab<<ac<<ad;
        return 0;
    }
    if((cb[2]=='D')||(cb[2]=='F')){
        if((cd[2]=='D')||(cd[2]=='F')){
            ac=1;
            ad=1;
        }else{
            cout<<aa<<ab<<ac<<ad;
            return 0;
        }
    }else{
        if((cd[2]=='D')||(cd[2]=='F')){
            cout<<aa<<ab<<ac<<ad;
            return 0;
        }
        ac=1;
    }
    if(((cb[2]=='A')&&(cd[2]=='B'))||((cb[2]=='B')&&(cd[2]=='A'))||((cb[2]=='B')&&(cd[2]=='C'))||((cb[2]=='c')&&(cd[2]=='B'))){
        ad=1;
    }
    cout<<aa<<ab<<ac<<ad;

    return 0;
}
