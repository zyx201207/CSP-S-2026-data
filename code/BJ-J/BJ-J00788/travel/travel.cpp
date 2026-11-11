#include<bits/stdc++.h>
using namespace std;
string ra,rb,xa,xb;
int a[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>ra>>rb>>xa>>xb;
    if(ra[0]==xa[0]&&ra[1]==xa[1]){
        a[1]=1;
        if(rb[0]==xb[0]&&rb[1]==xb[1]){
            a[2]=1;
            if((rb[2]=='A'||rb[2]=='B'||rb[2]=='C')&&(xb[2]=='A'||xb[2]=='B'||xb[2]=='C')){
                a[3]=1;
                if(rb[2]+xb[2]!='A'+'C'){
                    a[4]=1;
                }
            }
            if(rb[2]+xb[2]=='D'+'F'){
                a[3]=1;
                a[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++){
        cout<<a[i];
    }
    return 0;
}
