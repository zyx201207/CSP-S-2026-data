#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char x,y;
    cin>>a>>b>>x>>c>>d>>y;

    if(a==c){
        cout<<"1";
        if(b==d){
            cout<<"1";
            if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
                cout<<"1";
                if(x=='B'||y=='B')cout<<"1";
                else cout<<"0";
            }
            else if(x=='D'&&y=='F'){
                cout<<"11";
            }
            else if(x=='F'&&y=='D'){
                cout<<"11";
            }
            else cout<<"00";
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else cout<<"0000";
    return 0;
}
