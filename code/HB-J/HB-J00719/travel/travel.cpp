#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    bool flag=true,flag1=false,flag2=false;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        flag2=true;
    };
    cout<<flag2?1:0;
    for(int i=0;i<=1;i++){
        if(s1[i]!=s2[i]){
        flag=false;
        }
    }
    cout<<(flag&&flag2)?1:0;
    if(((s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&flag&&flag2){
        flag1=true;
    };
    cout<<flag1?1:0;
    if((s1[2]-s2[2]==1||s1[2]-s2[2]==-1)&&flag1){
        cout<<1;
    }
    else{
    cout<<0;
    }
    return 0;
}

