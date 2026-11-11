#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    bool a=0,b=0,c=0,d=0;
    if(a1==b1){
        a=1;
        for(int i=0;i<2;i++){
            if(a2[i]!=b2[i]) break;
            if(i==1){
                b=1;
                if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
                    if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
                        c=1;
                        if(a2[2]+1==b2[2]||a2[2]-1==b2[2]) d=1;
                    }
                }else{
                    if(b2[2]=='D'||b2[2]=='F'){
                        c=1,d=1;
                    }
                }
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
