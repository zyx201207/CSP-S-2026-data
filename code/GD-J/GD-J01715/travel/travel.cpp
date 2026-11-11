#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    bool q=0,p=0;
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1] && s1!=s2){
        cout<<1;
        q=1;
    }
    else{
        cout<<0;
    }
    if(s1[2]<68 && q){
        if(s2[2]<68){
            cout<<1;
            p=1;
        }
        else{
            cout<<0;
        }
    }
    else{
        if(s2[2]>67){
            cout<<1;
            p=1;
        }
        else{
            cout<<0;
        }
    }
    if((s1[2]-s2[2]==-1 || s1[2]-s2[2]==1) && p){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
