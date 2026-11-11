#include <bits/stdc++.h>
using namespace std;
bool e,f,g,h;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,i,j;
    cin>>a>>b>>c>>d;

    if(a==c){
        e=1;

        if(b[0]==d[0]&&b[1]==d[1]){
            f=1;
            if(b[2]<'D'&&d[2]<'D'){
                g=1;
                if(b[2]==d[2]-1||b[2]==d[2]-1){
                    h=1;
                }
            }
            else if(b[2]>='D'&&d[2]>='D'){
                g=1;
                if(b[2]==d[2]-1||d[2]==b[2]-1){
                    h=1;
                }
            }
            else{
                g=0;
            }
        }
    }
    else{
        e=0;
    }
    cout<<e<<f<<g<<h;
    return 0;
}

