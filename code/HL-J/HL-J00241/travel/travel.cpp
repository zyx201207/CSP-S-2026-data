#include<bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1==n2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            int a1=0,a2=0;
            if((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C')) a1=1;
            if((s1[2]=='D')||(s1[2]=='F')) a1=2;
            if((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C')) a2=1;
            if((s2[2]=='D')||(s2[2]=='F')) a2=2;
            if(a1==a2){
                cout<<1;
                if((s1[2]=='A')&&(s2[2]=='B')) cout<<1;
                else if((s1[2]=='B')&&(s2[2]=='C')) cout<<1;
                else if((s1[2]=='D')&&(s2[2]=='F')) cout<<1;
                else if((s2[2]=='A')&&(s1[2]=='B')) cout<<1;
                else if((s2[2]=='B')&&(s1[2]=='C')) cout<<1;
                else if((s2[2]=='D')&&(s1[2]=='F')) cout<<1;
                else cout<<0;
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
