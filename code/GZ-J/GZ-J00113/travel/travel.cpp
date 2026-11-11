//GZ-J00113  王铭皓 贵州省贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c,b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<"1";
            if(b[2]<='C' &&d[2]<='C' ){
                cout<<"1";
                if(b[2]=='A'&&d[2]=='B') cout<<"1";
                else if(b[2]=='B'&&d[2]=='C') cout<<"1";
                else if(b[2]=='C'&&d[2]=='B') cout<<"1";
                else cout<<"0";
            }
            else if(b[2]>'C'&&d[2]>'C'){
                cout<<"11";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
