#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string xa,xb;
    int a,b;
    char sa,sb;
    cin>>xa>>a>>sa>>xb>>b>>sb;

    if(xa==xb){
        cout<<1;
        if(a==b){
            cout<<1;
            if(sa>='D'&&sa<='F'&&sb>='D'&&sb<='F'){
                cout<<11;
            }else if(sa>='A'&&sa<='C'&&sb>='A'&&sb<='C'){
                cout<<1;
                if(sa=='C'&&sb=='A'||sa=='A'&&sb=='C'){
                    cout<<0;
                }
                else{
                    cout<<1;
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

