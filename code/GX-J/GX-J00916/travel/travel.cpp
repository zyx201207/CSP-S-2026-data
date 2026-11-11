#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int flag=0;
    if(a==c){
        cout<<'1';
        if(b[0]==d[0] && b[1]==d[1]){
            cout<<'1';
            if(abs(int(b[2]-d[2]))<=2 && b[2]!=d[2] && int(b[2]+d[2])!=135 ){
                cout<<'1';
                if(abs(int(b[2]-d[2]))==1){
                    cout<<'1';
                }else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }

    }else{
        cout<<"0000";
    }
    return 0;
}
