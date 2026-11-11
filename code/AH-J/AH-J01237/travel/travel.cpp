#include<bits/stdc++.h>
using namespace std;
string c1,d1,c2,d2,a;
int w;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>d1>>c2>>d2;
    a="0000";
    if(c1==c2){
        a[0]='1';
        if(d1[0]==d2[0]&&d1[1]==d2[1]){
            a[1]='1';
            if(d1[2]<='C'&&d2[2]<='C'){
                a[2]='1';
                w=d1[2]-d2[2];
                if(w==1||w==-1){
                    a[3]='1';
                    cout<<a;
                }else{
                    cout<<a;
                }
            }else if(d1[2]>='D'&&d2[2]>='D'){
                a[2]='1';
                a[3]='1';
                cout<<a;
            }else{
                cout<<a;
            }
        }else{
            cout<<a;
        }
    }else{
        cout<<a;
    }
    return 0;
}
