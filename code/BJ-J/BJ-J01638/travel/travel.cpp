#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool flag=false;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string x,y;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    for(int i=0;i<=1;i++){
        x+=s1[i];
    }
    for(int i=0;i<=1;i++){
        y+=s2[i];
    }
    if(x==y && c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(x==y && c1==c2){
        if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
            flag=true;
            cout<<1;
        }
        else if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'){
            flag=true;
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    if(x==y && flag==true && c1==c2){
        if(s1[2]+1==s2[2] || s2[2]+1==s1[2] ){
            cout<<1;
        }
        else if(s1[2]=='D' && s2[2]=='F'){
            cout<<1;
        }
        else if(s1[2]=='F' && s2[2]=='D'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    return 0;

}
