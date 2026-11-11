#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    int t1=0,t2=0,t=1;
    for(int i=1;i>=0;i--){
        t1+=(s1[i]-'0')*t;
        t2+=(s2[i]-'0')*t;
        t*=10;
    }
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2){
        if(t1==t2){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    if(c1==c2){
        if(t1==t2){
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
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
    if(c1==c2){
        if(t1==t2){
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
                if(s1[2]+1==s2[2]||s1[2]-1==s2[2]||s1[2]+1=='D'&&s2[2]=='F'){
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
    }else{
        cout<<0;
    }

    return 0;
}
