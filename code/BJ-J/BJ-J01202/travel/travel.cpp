#include <bits/stdc++.h>
using namespace std;
string rt,rc,xt,xc;
bool f[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rt>>rc>>xt>>xc;
    if(rt==xt){
        f[0]=1;
        if(rc[0]==xc[0]&&rc[1]==xc[1]){
            f[1]=1;
            if(rc[2]<='C'&&xc[2]<='C'||rc[2]>='D'&&xc[2]>='D'){
                f[2]=1;
                if(rc[2]-1==xc[2]||rc[2]+1==xc[2]) f[3]=1;
            }
        }
    }
    for(int i=0;i<4;i++) cout<<f[i];
    return 0;
}
