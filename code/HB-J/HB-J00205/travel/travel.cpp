#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    struct tre{
        string s;
        string m;
    }a[N];
    for(int i=1;i<=2;i++){
        cin>>a[i].s>>a[i].m;
    }
    if(a[1].s==a[2].s){
        cout<<1;
        if(a[1].m[0]==a[2].m[0] && a[1].m[1]==a[2].m[1]){
            cout<<1;
            if(a[1].m[2]<='C' && a[2].m[2]<='C' || a[1].m[2]>'C' && a[2].m[2]>'C'){
                cout<<1;
                if(a[1].m[2]-a[2].m[2]==1 || a[2].m[2]-a[1].m[2]==1){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
