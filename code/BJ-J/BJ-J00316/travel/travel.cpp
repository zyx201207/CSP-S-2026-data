#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;//表示第一个人的车厢和位置，第二个人的车厢和位置
    cin>>c1>>s1>>c2>>s2;
    string l1=s1.substr(0,2);//这两个分别表示两个人的行数
    string l2=s2.substr(0,2);
    bool isleft1=s1[2]<='C';
    bool isleft2=s2[2]<='C';
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&l1==l2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&l1==l2&&isleft1==isleft2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&l1==l2&&isleft1==isleft2){
        if(isleft1==0){
            cout<<1;
            return 0;
        }else if(isleft1==1){
            if(abs(s1[2]-s2[2])==1){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    return 0;
}