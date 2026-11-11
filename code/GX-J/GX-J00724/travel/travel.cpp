#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                cout<<(d[2]=='A'||d[2]=='B'||d[2]=='C');
                cout<<(abs(d[2]-b[2])==1);
            }else if(b[2]=='D'||b[2]=='F'){
                cout<<(d[2]=='D'||d[2]=='F');
                cout<<(abs(d[2]-b[2])==1);
            }else{
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
