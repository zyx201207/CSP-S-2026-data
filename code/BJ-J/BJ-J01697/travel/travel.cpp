#include <bits/stdc++.h>
using namespace std;
bool f[4];
int cx,cx2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    bool ddd,sss,mmm;
    cin >> cx  >> a >> cx2 >> b;
    if(cx==cx2){
        sss=1;
        f[0]=1;
    }
    if(sss==1 && (a[0]+a[1]) == b[0]+b[1]){
        ddd=1;
        f[1]=1;
    }
    if(ddd==1){
        if(a[2]>='D' && b[2]>='D'){
            mmm=1;
            f[2]=1;
        }
        if(a[2]<'D' && b[2] < 'D'){
            mmm=1;
            f[2]=1;
        }
    }
    if(mmm==1){
        if(a[2]==b[2]+1 || a[2]==b[2]-1){
            f[3]=1;
        }
    }
    for(int i =0;i<4;i++){
        cout << f[i];
    }
    return 0;

}
