#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        if(b[0]==d[0]&&b[1]==d[1]){
            int o1=0,o2=0;
            if(b[2]<='C'){
                o1=1;
            }
            if(d[2]<='C'){
                o2=1;
            }
            if(o1==o2){
                if(b[2]==d[2]+1||b[2]==d[2]-1){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
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
