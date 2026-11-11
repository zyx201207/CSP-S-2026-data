#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<1;
        if(c2[0]==s2[0]&&c2[1]==s2[1]){
            cout<<1;
            char zuo1=c2[2];
            char zuo2=s2[2];
            if(zuo1=='A'||zuo1=='B'||zuo1=='C'){
                if(zuo2=='A'||zuo2=='B'||zuo2=='C'){
                    cout<<1;
                    if(abs(zuo1-zuo2)==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
            }else if(zuo1=='D'||zuo1=='F'){
                if(zuo2=='F'||zuo2=='D'){
                    cout<<1;
                    cout<<1;
                }else{
                    cout<<"00";
                }
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
}
