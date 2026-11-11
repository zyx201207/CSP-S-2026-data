#include <bits/stdc++.h>
using namespace std;
int a,b,ansa,ansb,ansc,ansd;
string inputa,inputb;
int c,d,seata,seatb;



int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a;cin>>inputa;cin>>b;cin>>inputb;
    c=inputa[2];d=inputb[2];
    if (a==b){
        ansa=1;
    }

    if (inputa[1]==inputb[1]&&ansa==1){
        ansb=1;
    }

    if(ansa==1 && ansb==1){
    if(c==68&&d==70||d==68&&c==70){
        ansc=1;ansd=1;
    }
    if(c==65||c==66||c==67){
        if(d==65||d==66||d==67){
            ansc=1;
        }
    }
    }


    if(c++==d ||c--==d && c!=68 && d!=68){
        ansd=1;
        if (ansb==0){
            ansd=0;
        }
    }
    cout<<ansa<<ansb<<ansc<<ansd;
    return 0;
}
