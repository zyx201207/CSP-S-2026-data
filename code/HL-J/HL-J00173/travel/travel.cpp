#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if ((a[1]==c[1])&&(a[0]==c[0])){
        if (b[0]==d[0]&&b[1]==d[1]){
            if ((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
                if(b[2]+1==d[2]||b[2]-1==d[2]){
                    cout<<"1111";
                }
                else if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }

    return 0;
}
