#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char x,y;
    bool f=0;
    cin>>a>>c>>x;
    cin>>b>>d>>y;
    if(a==b){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(c==d){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    //
    if(x<='C'&&x>='A'&&y>='A'&&y<='C'){
        cout<<"1";
        if(x=='B'||y=='B'){
            cout<<"1";
        }
        else{
            cout<<"0";
        }

    }
    else if(x>='D'&&x<='F'&&x!='E'&&y>='D'&&y<='F'&&y!='E'){
        cout<<"11";
    }
    else{
        cout<<"00";
    }
    return 0;
}
