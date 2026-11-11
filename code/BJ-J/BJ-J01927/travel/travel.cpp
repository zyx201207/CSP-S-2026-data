#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<"1";
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<"a1";
            if(!((c[2]=='C'&&d[2]=='D')||(c[2]=='D'&&d[2]=='C'))){
                cout<<"1";
                if(c[2]+1==d[2]||c[2]-1==d[2]){
                        cout<<"1";
                }else {
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
