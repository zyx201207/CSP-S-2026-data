#include <bits/stdc++.h>
using namespace std;

int main(){
    int rc,xc;
    char rz[3],xz[3];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> rc;
    cin >> rz[0] >>rz[1]>>rz[2];
    cin >> xc;
    cin >> xz[0] >> xz[1]>>xz[2];

    int rzz=rz[2],xzz=xz[2];

    if(rc==xc){
        cout << 1;
            if(rz[0]==xz[0]&&rz[1]==xz[1]){
                cout << 1;
                if(rzz<=67&&xzz<=67){
                    cout << 1;
                }else{
                    if(rzz==68&&xzz==69){
                        cout << 1;
                    }else{
                        if(rzz==69&&xzz==68){
                            cout << 1;
                        }else{
                            cout << 0;
                        }
                    }
                }
            }else{
                cout << 0 << 0;
            }
    }else{
        cout << 0 << 0 << 0;
    }

    if((rz[0]==xz[0]&&rz[1]==xz[1]&&(rz[2]==xz[2]+1||rz[2]==xz[2]-1)&&max(rz[2],xz[2])<=67)){
        cout << 1;
    }else{
        if(rz[2]==69&&xz[2]==68||rz[2]==68&&xz[2]==69){
            cout << 1;
        }else{
            cout<<0;
        }

    }

    return 0;
}
