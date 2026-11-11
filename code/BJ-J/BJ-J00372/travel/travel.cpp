#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<"1";
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<"1";
            if('A'<=c[2]&&c[2]<='C'){
                if('A'<=d[2]&&d[2]<='C'){
                    cout<<"1";
                    if(d[2]==c[2]+1||c[2]==d[2]+1){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    cout<<"00";
                }
            }else{
                if('D'<=d[2]&&d[2]<='E'){
                    cout<<"11";
                }else{
                    cout<<"00";
                }
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
