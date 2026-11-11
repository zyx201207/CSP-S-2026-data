#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx1>>b1>>cx2>>b2;
    if(cx1!=cx2){
        cout<<"0000";
    }
    else{
        cout<<1;
        if(b1[0]!=b2[0] or b1[1]!=b2[1]){
            cout<<"000";
        }
        else{
            cout<<1;
            if(((b1[2]=='D' or b1[2]=='E') and (b2[2]!='D' and b2[2]!='E'))
               or ((b1[2]=='A' or b1[2]=='B' or b1[2]=='C')and(b2[2]!='A' and b2[2]!='B' and b2[2]!='C'))){
                cout<<"00";
            }
            else{
                cout<<1;
                if(b1[2]=='E'){
                    if(b2[2]=='D')cout<<1;
                    else cout<<0;
                }
                if(b1[2]=='D'){
                    if(b2[2]=='E')cout<<1;
                    else cout<<0;
                }
                if(b1[2]=='C'){
                    if(b2[2]=='B')cout<<1;
                    else cout<<0;
                }
                if(b1[2]=='B'){
                    if(b2[2]=='A' or b2[2]=='B')cout<<1;
                    else cout<<0;
                }
                if(b1[2]=='A'){
                    if(b2[2]=='B')cout<<1;
                    else cout<<0;
                }


            }
        }
    }
    return 0;
}