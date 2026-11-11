#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,x1,y,y1;
    char a,b;
    cin>>x>>x1>>a>>y>>y1>>b;
    if(x==y){
        cout<<'1';
        if(x1==y1){
            cout<<'1';
            if((a<='C' && b<='C') || (a>'C' && b>'C')){
                cout<<'1';
                if((a=='B' && b=='A')||(a=='A'&& b=='B')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
                    cout<<'1';
                }
                else cout<<'0';
            }
            else cout<<"00";
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
