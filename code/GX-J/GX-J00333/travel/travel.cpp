#include<bits/stdc++.h>
using namespace std;

string a,b,sta,stb;
int ina,inb;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>sta>>b>>stb;
    if(a==b){
        cout<<1;
        ina=(sta[0]-'0')*10+(sta[1]-'0');
        inb=(stb[0]-'0')*10+(stb[1]-'0');
        if(ina==inb){
            cout<<1;
            if(sta[2]>='D'&&stb[2]>='D'||sta[2]<='C'&&stb[2]<='C'){
                cout<<1;
                if(abs(sta[2]-stb[2])==1){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";





    return 0;
}
