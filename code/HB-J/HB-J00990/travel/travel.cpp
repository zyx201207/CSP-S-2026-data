#include<bits/stdc++.h>
using namespace std;
string sx,sy,tx,ty;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sx>>sy>>tx>>ty;
    if(sx!=tx){
        cout<<"0000";
        return 0;
    }
    else if(sy[0]!=ty[0] || sy[1]!=ty[1]){
        cout<<"1000";
        return 0;
    }
    else if(sy[2]>='D' && ty[2]<'D'){
        cout<<"1100";
        return 0;
    }
    else if(sy[2]<'D' && ty[2]>='D'){
        cout<<"1100";
        return 0;
    }
    else if(abs(sy[2]-ty[2])>1){
        if(sy[2]!='F' && ty[2]!='D'){
            if(sy[2]!='D' && ty[2]!='F'){
                cout<<"1110";
                return 0;
            }
        }
    }
    cout<<"1111";
    return 0;
}
