#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string r1,r2,lx1,lx2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>r1>>r2>>lx1>>lx2;
    if (r1!=lx1) cout<<"0000";
    else{
        ll rp=(r2[0]-'0')*10+r2[1]-'0',xp=(lx2[0]-'0')*10+lx2[1]-'0';
        if (rp!=xp){
            cout<<"1000";
            return 0;
        }
        char cr=r2[2],clx=lx2[2];
        if (!(cr<='C' && clx<='C' || cr>='D' && clx>='D')){
            cout<<"1100";
            return 0;
        }
        if (cr>clx) swap(cr,clx);
        if (clx-cr==1) cout<<"1111";
        else cout<<"1110";
    }
    return 0;
}