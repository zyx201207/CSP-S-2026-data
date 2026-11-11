#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a, b, c, d;
    cin >> a >> b >>c >>d;
    int jie=0;
    for(int i=0; i<2; i++){
        if(a[i]==c[i]){
            jie++;
        }
    }
    int nn=0;
    int mm=0;
    int we=1;
    for(int i=1; i>=0; i--){
        nn+=b[i]*we;
        mm+=d[i]*we;
        we*=10;
    }
    if(jie==2){
        cout << 1;
        if(nn==mm){
            cout << 1;
            if(b[2]<='C'&&d[2]<='C' || b[2]>='D'&& d[2]>='D'){
                cout << 1;
            }else{
                cout << 0;
            }
            int x=0;
            int y=0;
            int wei=1;
            for(int i=1; i>=0; i--){
                x+=b[i]*wei;
                y+=b[i]*wei;
                wei*=10;
            }
            if(x+1==y || x-1==y){
                cout << 1;
            }else if((char)b[2]+1 == d[2] || (char)b[2]-1==d[2]){
                if((char)b[2]+1 == d[2]&&b[2]!='C'){
                    cout << 1;
                }else if((char)b[2]-1 == d[2]&& b[2]!='A'){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << 0;
            }
        }else{
            cout << 0 << 0;
            if((char)b[2]+1 == d[2] || (char)b[2]-1==d[2]){
                if((char)b[2]+1 == d[2]&&b[2]!='C'&&nn==mm){
                    cout << 1;
                }else if((char)b[2]-1 == d[2]&& b[2]!='A'&& nn==mm){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << 0;
            }
        }
    }else{
        cout << 0 << 0<< 0<< 0;
    }

    return 0;
}
