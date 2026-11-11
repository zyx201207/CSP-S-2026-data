#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel","w",stdout);
    string a,b,c,d;
    cin>>a>>c>>b>>d;
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<1;
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<1;
            int x=c[2]-0,y=d[2]-0;
            if(x>=65&&x<=67&&y>=65&&y<=67||x>=68&&x<=69&&y>=68&&y<=69){
                cout<<1;
                int c=x-y;
                if(c<0){
                    c=c*-1;
                }
                if(c==1){
                    cout<<1;
                }
                else{
                    cout<<0;
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
