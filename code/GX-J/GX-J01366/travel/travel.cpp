#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string acx,azw,bcx,bzw;
    cin>>acx>>azw>>bcx>>bzw;
    int tongcx=0,tongp=0,tongc=0,xiangl=0;
    if(acx==bcx){
        tongcx=1;

        if(azw[0]==bzw[0] && azw[1]==bzw[1]){
            tongp=1;

            if( (azw[2]>='A'&&azw[2]<='C' && bzw[2]>='A'&&bzw[2]<='C') || (azw[2]>='D'&&azw[2]<='F' && bzw[2]>='D'&&bzw[2]<='F') ){
                tongc=1;

                if( (char(azw[2]+1)==bzw[2] || char(azw[2]-1)==bzw[2]) && (azw[2]>='A'&&azw[2]<='C' && bzw[2]>='A'&&bzw[2]<='C') || (azw[2]>='D'&&azw[2]<='F' && bzw[2]>='D'&&bzw[2]<='F') ){
                    xiangl=1;
                }

            }

        }

    }

    cout<<tongcx<<tongp<<tongc<<xiangl;

    return 0;
}
//1 02 01A 02 01B
//2 02 01C 02 01A
//3 02 01C 02 01D
//4 02 02B 02 01A
//5 02 01A 03 01A
