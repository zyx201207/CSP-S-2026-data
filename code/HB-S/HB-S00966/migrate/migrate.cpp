#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t,kawai[1000010],tempp,res;
//shen sou

void dfs(LL XX,LL YY,LL temppp){
    if(kawai[YY]-kawai[temppp]>=t){
        if(tempp<temppp)temppp=tempp;
    }
    for(LL r=temppp;r<=YY;r++){//temppp:XX++
        if(kawai[r]-kawai[temppp]>=t){
            dfs(1+r,YY,tempp+1);
            res++;
        }
        else break;//zhi jie pass.
    }
    return;
}
int main(){
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    //if(c!=0)return 0;
    for(LL k=0;k<=t+1;k++)cin>>kawai[k];
    for(LL p=0;p<=t+1;p++)
        for(LL z=0;z<t;z++)cin>>kawai[z];
    for(int i=0;i<t;i++){
        dfs(kawai[i],kawai[i+1],i);
        res++;
        cout<<res<<endl;
    }

    return 0;
}
