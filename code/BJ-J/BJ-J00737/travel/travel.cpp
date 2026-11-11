#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    //cout<<(c1==c2);
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    bool flag=1;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i])flag=0;
    }
    cout<<flag;
    if(flag==0){
        cout<<"00";
        return 0;
    }
    int flag2=1;
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){cout<<1;flag=1;}
    else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){cout<<1;flag=2;}
    else {cout<<0;flag2=0;}
    if(flag2==0){
        cout<<0;
        return 0;
    }
    if(flag==1&&abs(s1[2]-s2[2])==1){
        cout<<1;
    }else if(flag==2&&abs(s1[2]-s2[2])==2){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
