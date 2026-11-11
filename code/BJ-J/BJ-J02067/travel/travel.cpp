#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string r2,x2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;

    if(r1==x1){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    bool f=true;
    for(int i=0;i<=1;i++){
        if(r2[i]=x2[i]){
            f=false;
        }
    }
    if(f){
        cout<<1;
    }else{

        cout<<"000";
        return 0;

    }
    if(f&&(('A'<=r2[2]&&r2[2]<='C'&&'A'<=x2[2]&&x2[2]<='C'&&'D'<=r2[2]&&r2[2]<='F'&&'D'<=x2[2]&&x2[2]<='F'))){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((('A'<=r2[2]&&r2[2]<='C'&&'A'<=x2[3]&&x2[2]<='C'))){
        if(f&&(r2[2]-x2[2]==1||x2[2]-r2[2]==1)){
            cout<<1;
        }else{
            cout<<0;

        }
    }else if('D'<=r2[3]&&r2[2]<='F'&&'D'<=x2[3]&&x2[2]<='F'){

        if(f&&(r2[2]-x2[2]==2||x2[2]-r2[2]==2)){
            cout<<1;
        }else{
            cout<<0;

        }
    }else{

        cout<<0;
    }
    return 0;
}
