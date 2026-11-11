#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long r,x;
    string rt,xt;
    cin>>r>>rt>>x>>xt;
    long long rh=int(int(rt[0])-int('0'))*10+int(int(rt[1])-int('0'));
    long long xh=int(int(xt[0])-int('0'))*10+int(int(xt[1])-int('0'));
    long long rs=int(rt[2])-int('A')+1;
    long long xs=int(xt[2])-int('A')+1;
    if(r==x){
        cout<<1;
        if(rh==xh){
            cout<<1;
            if((rs<=3&&xs<=3)||(rs>=4&&xs>=4)){
                cout<<1;
                if((abs(xs-rs)==1)||(rs==4&&xs==6)||(rs==6&&xs==4)){
                    cout<<1;
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
    else{
        cout<<"0000";
    }
    return 0;
}
