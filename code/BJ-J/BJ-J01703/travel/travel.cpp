#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int k1,k2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<"1";
        if(c2[0]==c4[0]&&c2[1]==c4[1]){
            cout<<"1";
            k1=c2[2]-'A'+1,k2=c4[2]-'A'+1;
            if(k1<=3&&k2<=3||k1>=4&&k2>=4){
                cout<<"1";
                if(max(k1,k2)-min(k1,k2)==1){
                    cout<<"1\n";
                }else {
                    cout<<"0\n";
                }
            }else {
                cout<<"00\n";
            }
        }else {
            cout<<"000\n";
        }
    }else {
        cout<<"0000\n";
    }


    return 0;
}
