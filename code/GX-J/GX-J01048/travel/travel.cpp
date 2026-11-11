#include<bits/stdc++.h>
using namespace std;
string x,z,xx,zz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>z>>xx>>zz;
    // cout<<z[2]<<zz[2]<<endl;
    if(x==xx){
        cout<<1;
    }else{
    cout<<0<<0<<0<<0;
    return 0;
    }
    if(z[0]==zz[0]&&z[1]==zz[1]){
        cout<<1;
    }else{
    cout<<0<<0<<0;
    return 0;
    }
    if(z[2]<'D'){
        if(zz[2]<'D'){
                if(z[2]-zz[2]==1||zz[2]-z[2]==1){
                    cout<<11;
                    return 0;
                }else{
                    cout<<10;
            return 0;
                }

        }
        else{
            cout<<0<<0;
            return 0;
        }
    }else{
    if(zz[2]>='D'){
        cout<<11;
        return 0;
    }
    else{
        cout<<0<<0;
        return 0;
    }


    }
    return 0;

}
