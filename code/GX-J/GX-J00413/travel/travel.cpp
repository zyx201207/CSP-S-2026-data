#include<bits/stdc++.h>
using namespace std;
int x1,x2,a[10];
string y1,y2;
int main{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    a[0]=1;
    if(y1[0]==y2[0] && y1[1]==y2[1]){
        a[1]=1;
    }else{
        a[1]=0;
    }
    if((y1[2]=='A'||y1[2]=='B'||y1[2]=='c'||)&&(y1[2]=='A'||y1[2]=='B'||y1[2]=='C'||)){
        a[2]=1;
    }else if((y1[2]=='D'||y1[2]=='F')&&(y1[2]=='D'||y1[2]=='F')){
        a[2]=1;
    )else{
        a[2]=0;
    }
    if(a[2]==0){
        a[3]=0;
    }else if(y1=='D'||y1=='F'){
        a[3]=1;
    }else if((y1=='A'&&y2=='B')||(y1=='B'&&y2=='A')){
        a[3]=1;
    }else if((y1=='B'&&y2=='C')||(y1=='C'&&y2=='B')){
        a[3]=1;
    }
    for(int i=0;i<=3;i++){
        cout<<a[i]
    }
    return 0;
}
