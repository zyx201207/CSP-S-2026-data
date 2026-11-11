#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int c=0,s=0,x=0,y=0;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<c1.size();i++){
        c=c*10+(c1[i]-'0');
    }
    for(int i=0;i<c2.size();i++){
        s=s*10+(c2[i]-'0');
    }
    for(int i=0;i<s1.size()-1;i++){
        x=x*10+(s1[i]-'0');
    }
    for(int i=0;i<s2.size()-1;i++){
        y=y*10+(s2[i]-'0');
    }
    if(c==s){
        cout<<1;
        if(x==y){
            cout<<1;
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
                cout<<1;
                if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1) cout<<1;
                else cout<<0;
            }
            else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
                for(int i=1;i<=2;i++) cout<<1;
            }
            else{
                for(int i=1;i<=2;i++) cout<<0;
            }
        }
        else{
            for(int i=1;i<=3;i++) cout<<0;
        }
    }
    else{
        for(int i=1;i<=4;i++) cout<<0;
    }
    return 0;
}

