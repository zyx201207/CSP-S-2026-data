#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int c[105];
int R,Rset[a][b][c],X,Xset[a][b][c];
int mian(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ans,type,num,close;
    cin>>R>>Rset[a][b][c]>>X>>Xset[a][b][c];
    if(R==X){
        ans++1;
    }
    else{
        ans=0;
    }
    if(Rset[a][b]==Xset[a][b]){
        type+=1;
    }
    else{
        type=0;
    }
    if(Rest[c]=="A"||"B"||"C"&&Xset[c]=="A"||"B"||"C"){
        num+=1;
    }
    else{
        num=0;
    }
    if(Rset[a][b]+1==Xset[a][b]||Rset[a][b]-1==Xset[a][b]){
        close+=1;
    }
    else{
        close=0;
    }
    cout<<ans<<" "<<type<<" "<<num<<" "<<close;
    return 0;
}



