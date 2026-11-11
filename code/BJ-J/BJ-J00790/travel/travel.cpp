#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string sa1,sa2,sb1,sb2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>sa1>>sa2>>sb1>>sb2;
    if(sa1==sb1){
        if(sa2[0]==sb2[0]&&sa2[1]==sb2[1]){
            if((sa2[2]<='C'&&sb2[2]<='C')||(sa2[2]>='D'&&sb2[2]>='D')){
                if((sa2[2]>='D'&&sb2[2]>='D')||(sa2[2]<='C'&&sb2[2]<='C'&&abs((int)(sa2[2]-sb2[2]))==1)){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
