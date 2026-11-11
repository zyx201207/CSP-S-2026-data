#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>c>>b>>d;
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<1;
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<1;
            if(c[2]>='A'&&c[2]<='C'){
                if(d[2]>='A'&&d[2]<='C'){
                    cout<<1;
                    if(c[2]==d[2]-1||c[2]==d[2]+1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
            }else{
                if(d[2]>='D'&&c[2]<='E'){
                    cout<<1;
                    if(c[2]==d[2]-1||c[2]==d[2]+1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
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
