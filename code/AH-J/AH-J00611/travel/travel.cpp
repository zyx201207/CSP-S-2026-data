#include<bits/stdc++.h>
using namespace std;
string tr,tx,cr,cx;
int ir,ix;
bool cer,cex;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>tr>>cr>>tx>>cx;
    if(cr[2]=='A'||cr[2]=='B'||cr[2]=='C') cer=false;
    else if(cr[2]=='D'||cr[2]=='F') cer=true;

    if(cx[2]=='A'||cx[2]=='B'||cx[2]=='C') cex=false;
    else if(cx[2]=='D'||cx[2]=='F') cex=true;

    if(tr==tx){
        cout<<'1';
        if(cr[0]==cx[0]&&cr[1]==cx[1]){
            cout<<'1';
            if(cer==cex){
                cout<<'1';
                if(cr[2]==cx[2]-1||cr[2]==cx[2]+1) cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;

}
