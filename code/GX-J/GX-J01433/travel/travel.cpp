#include<bits/stdc++.h>
using namespace std;
struct node{
    string xiang,wei;
}a[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a[1].xiang>>a[1].wei;
    cin>>a[2].xiang>>a[2].wei;
    if(a[1].xiang!=a[2].xiang){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if((a[1].wei[0]==a[2].wei[0]) && (a[1].wei[1]==a[2].wei[1])){
            cout<<"1";
            if(((a[1].wei[2]=='A' || a[1].wei[2]=='B' || a[1].wei[2]=='C') && (a[2].wei[2]=='A' || a[2].wei[2]=='B' || a[2].wei[2]=='C')) || ((a[1].wei[2]=='D' || a[1].wei[2]=='F') && (a[2].wei[2]=='D' || a[2].wei[2]=='F'))){
                cout<<"1";
                if(((a[1].wei[2]=='A') && (a[2].wei[2]=='B')) || ((a[1].wei[2]=='B') && (a[2].wei[2]=='A')) || ((a[1].wei[2]=='B') && (a[2].wei[2]=='C')) || ((a[1].wei[2]=='C') && (a[2].wei[2]=='B')) || ((a[1].wei[2]=='D') && (a[2].wei[2]=='F')) || ((a[1].wei[2]=='F') && (a[2].wei[2]=='D'))){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    return 0;
}
