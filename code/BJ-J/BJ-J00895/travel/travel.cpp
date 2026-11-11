#include <bits/stdc++.h>
using namespace std;
char x[2],xx[3],r[2],rr[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out"，"w",stdout);
    cin>>x>>xx>>r>>rr;
    if(x[0]==r[0]&&x[1]==r[1]){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(xx[0]==rr[0]&&xx[1]==rr[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(xx[2]=='A'||xx[2]=='B'||xx[2]=='C'){
        if(rr[2]=='A'||rr[2]=='B'||rr[2]=='C'){
            cout<<1;
            if(abs((int)(rr[2])-(int)(xx[2]))<=1){
                cout<<1;
            }
            else cout<<0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(xx[2]=='D'||xx[2]=='F'){
        if(rr[2]=='D'||rr[2]=='F'){
            cout<<"11";
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    return 0;

}
