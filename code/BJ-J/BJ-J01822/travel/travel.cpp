#include<bits/stdc++.h>
using namespace std;
    char c2[10],c4[10];
    int c1,c3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<1;
        int n1,n2;
        n1=c2[0]*10+c2[1];
        n2=c4[0]*10+c4[1];
        if(n1==n2){
            cout<<1;
            if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>'C'&&c4[2]>'C')){
                cout<<1;
                if(max(c2[2],c4[2])-min(c2[2],c4[2])==1||(max(c2[2],c4[2])=='F'&&min(c2[2],c4[2])=='D'))cout<<1;
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";

    }
    else cout<<"0000";

return 0;}
