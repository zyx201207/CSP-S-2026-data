#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a,b,c,d,e,a1,b1,c1,d1,e1;
    cin>>a>>b>>c>>d>>e>>a1>>b1>>c1>>d1>>e1;
    if(a==a1 && b==b1){
        cout<<1;
        if(c1==c && d1==d){
            cout<<1;
            if(((e=='A' || e=='B' || e=='C')&&(e1=='A' || e1=='B' || e1=='C'))||((e=='D' || e=='F')&&(e1=='D' || e1=='F'))){
                cout<<1;
                if((e=='D' || e=='F')||(e=='A' && e1=='B')||(e1=='A' && e=='B')||(e1=='C'&&e=='B')||(e=='C'&&e1=='B')){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
