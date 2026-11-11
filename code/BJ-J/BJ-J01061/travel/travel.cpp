#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool flag1=true,flag2=true,flag3=true,flag4=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<1;
    }else{
        cout<<0;
        flag1=false;
    }

    if(flag1){
        if(c2[0]==c4[0]&&c2[1]==c4[1]){
            cout<<1;
        }
        else{
            cout<<0;
            flag2=false;
        }
    }else{
        cout<<0;
    }

    if(flag1&&flag2){
        if((c2[2]=='A'&&c4[2]=='B')||(c2[2]=='A'&&c4[2]=='C')||(c2[2]=='B'&&c4[2]=='C')||
            (c2[2]=='B'&&c4[2]=='A')||(c2[2]=='C'&&c4[2]=='A')||(c2[2]=='C'&&c4[2]=='B')||
            (c2[2]=='D'&&c4[2]=='F')||(c2[2]=='F'&&c4[2]=='D')){
                cout<<1;
            }else{
                cout<<0;
                flag3=false;
            }

    }
    else{
        cout<<0;
    }
    if(flag1&&flag2&&flag3){
        if((c2[2]=='A'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='C')||(c2[2]=='D'&&c4[2]=='F')||
            (c2[2]=='B'&&c4[2]=='A')||(c2[2]=='C'&&c4[2]=='B')||(c2[2]=='F'&&c4[2]=='D')
           ){
            cout<<1;
           }
           else{
            cout<<0;
            flag4=false;
           }
    }
    else{
        cout<<0;
    }
    return 0;
}
