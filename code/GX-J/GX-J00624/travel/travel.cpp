#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t[5],n,n1,g,g1;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='A'){
        n=1;
        g=1;
    }
    else if(s1[2]=='B'){
        n=2;
        g=1;
    }
    else if(s1[2]=='C'){
        n=3;
        g=1;
    }
    else if(s1[2]=='E'){
        n=10;
        g=0;
    }
    else{
        n=11;
        g=0;
    }
    if(s2[2]=='A'){
        n1=1;
        g1=1;
    }
    else if(s2[2]=='B'){
        n1=2;
        g1=1;
    }
    else if(s2[2]=='C'){
        n1=3;
        g1=1;
    }
    else if(s2[2]=='E'){
        n1=10;
        g1=0;
    }
    else{
        n1=11;
        g1=0;
    }
    if(c1==c2){
        t[0]=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            t[1]=1;
            if(g==g1){
                t[2]=1;
                if(n>n1){
                    if(n-n1==1){
                        t[3]=1;
                    }
                    else{
                        t[3]=0;
                    }
                }
                else{
                    if(n1-n==1){
                        t[3]=1;
                    }
                    else{
                        t[3]=0;
                    }
                }
            }
            else{
                t[2]=0;
                t[3]=0;
            }
        }
        else{
            t[1]=0;
            t[2]=0;
            t[3]=0;
        }
    }
    else{
        t[0]=0;
        t[1]=0;
        t[2]=0;
        t[3]=0;
    }

    cout<<t[0]<<t[1]<<t[2]<<t[3];

    return 0;
}
