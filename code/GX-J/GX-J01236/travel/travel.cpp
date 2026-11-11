#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int aq=0,bq=0,cq=0,dq=0;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        aq=1;
        if(b[1]+b[0]==d[1]+d[0]){
            bq=1;
            if(b[2]<='C'&&d[2]<='C'){
                cq=1;
            }
            else if(b[2]>='D'&&d[2]>='D'){
                cq=1;
            }
        }

        if(b[2]+1==d[2]){
            if(int(b[1])+int(b[0])*10==int(d[1])+int(d[0])*10){
                dq=1;
            }
        }
        else if(b[2]-1==d[2]){
            if(int(b[1])+int(b[0])*10==int(d[1])+int(d[0])*10){
                dq=1;
            }
        }
        else if(b[2]==d[2]){
            if(int(b[1])+int(b[0])*10+1==int(d[1])+int(d[0])*10){
                dq=1;
            }
            else if(int(b[1])+int(b[0])*10-1==int(d[1])+int(d[0])*10){
                dq=1;
            }
        }
    }
    cout<<aq<<bq<<cq<<dq;
    return 0;
}
