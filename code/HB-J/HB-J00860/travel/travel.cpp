#include<bits/stdc++.h>
using namespace std;
char m[15],n[15];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[15],b[15];
    cin>>a>>m>>b>>n;
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<1;
        if(m[0]==n[0]&&m[1]==n[1]){
            cout<<1;
            if((m[2]<='C'&&n[2]<='C')||(m[2]>='D'&&n[2]>='D')){
                cout<<1;
                if(m[2]+1==n[2]||m[2]-1==n[2]){
                    cout<<1;
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
