#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int a[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rs>>xc>>xs;
    if(rc[0]==xc[0]&&rc[1]==xc[1]){
        a[1]=1;
        if(rs[0]==xs[0]&&rs[1]==xs[1]){
            a[2]=1;
            if((rs[2]>'C'&&xs[2]>'C')||(rs[2]<='C'&&xs[2]<='C')){
                a[3]=1;
                if(abs(rs[2]-xs[2])==1) a[4]=1;
            }
        }
    }
    cout<<a[1]<<a[2]<<a[3]<<a[4];
    return 0;
}
