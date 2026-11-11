#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool t1=0,t2=0,t3=0;
    if(c1==c2){
        cout<<1;
        t1=1;
    }
    else{
        cout<<0;
    }
    if(t1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        t2=1;
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(t1&&t2){
        int sit1=s1[2]-'A';
        int sit2=s2[2]-'A';
        if((sit1<=2&&sit2<=2)||(sit1>2&&sit2>2)){
            cout<<1;
            t3=1;
        }
        else{
            cout<<"00";
        }
        if(t3){
            if(sit1-sit2==1||sit1-sit2==-1){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else{
        cout<<"00";
    }
    return 0;
}
