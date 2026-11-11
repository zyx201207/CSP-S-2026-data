#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>t1>>t2;
    if(s1==t1){
        a=1;
        if(s2[0]==t2[0]&&s2[1]==t2[1]){
            b=1;
            if(s2[2]<='C'&&s2[2]>='A'){
                if(t2[2]<='C'&&t2[2]>='A')c=1;
            }
            else{
                if(s2[2]<='F'&&s2[2]>='D')c=1;
            }
            if(c==1){
                if(s2[2]-t2[2]==1&&s2[2]<='B')d=1;
                if(s2[2]-t2[2]==-1&&s2[2]<='B')d=1;
                if(s2[2]=='D'&&t2[2]=='F')d=1;
                if(s2[2]=='F'&&t2[2]=='D')d=1;
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
