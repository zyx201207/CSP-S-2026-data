#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,pd=0;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        for(int i=0;i<2;i++){
            if(c[i]==d[i]){
                pd++;
            }
        }
        if(pd==2){
            cout<<1;
            if(c[2]<='C' && d[2]<='C' ||  c[2]>='D' && d[2]>='D'){
                cout<<1;
                if(c[2]=='A'&&d[2]=='B' || c[2]=='B'&&d[2]=='A' || c[2]=='B'&&d[2]=='C' || c[2]=='C'&&d[2]=='B' || c[2]=='F'&&d[2]=='D' || c[2]=='D'&&d[2]=='F'){
                    cout<<1;
                }
                else{
                    cout<<0;
                }

            }else{
                cout<<0;
                cout<<0;
            }
        }else{
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}