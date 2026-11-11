#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char x,y;
    cin>>a>>b>>x>>c>>d>>y;
    //cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<x<<endl<<y;
    //cout<<(a==c);
    if (a==c){
        cout<<1;
        if (b==d){
            cout<<1;
            int sss = (x=='A')+(x=='B')+(x=='C')+(y=='A')+(y=='B')+(y=='C');
            int ttt = (x=='D')+(x=='F')+(y=='D')+(y=='F');
            if (sss==2||ttt==2){
                cout<<1;
                if (ttt==2||x=='B'||y=='B'){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}