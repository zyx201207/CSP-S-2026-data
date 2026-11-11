#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char c1[2],c2[2],s1[3],s2[3];
bool flag[4]={1,1,1,1};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>c1;
    for(int i=0;i<3;i++){
        cin>>s1[i];
        if(s1[i]==' ')i--;
    }
    for(int i=0;i<2;i++){
        cin>>c2[i];
        if(c2[i]==' ')i--;
    }
    for(int i=0;i<3;i++){
        cin>>s2[i];
        if(s2[i]==' ')i--;
    }
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            flag[0]=0;
            flag[1]=0;
            flag[2]=0;
            flag[3]=0;
            break;
        }
    }
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            flag[1]=0;
            flag[2]=0;
            flag[3]=0;
            break;
        }
    }
    if(((s1[2]-'A')<3)^((s2[2]-'A')<3)){
        flag[2]=0;
        flag[3]=0;
    }
    if(
       ((s1[2]=='A')&&(s2[2]=='C'))
       ||((s1[2]=='C')&&(s2[2]=='A'))
    ){
        flag[3]=0;
    }
    for(int i=0;i<4;i++){
        cout<<flag[i];
    }
    return 0;
}
