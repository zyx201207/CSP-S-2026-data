#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3];
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a[0]>>a[1]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>d[0]>>d[1]>>d[2];
    if(a[0]==c[0] && a[1]==c[1]){
        if(b[0]==d[0] && b[1]==d[1]){
            if(b[2]<='C' && d[2]<='C'){
                if(b[2]=='B' || d[2]=='B'){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else if(b[2]>='D' && d[2]>='D'){
                cout<<"1111";
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
