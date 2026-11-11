#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int ans=0,sum=0,cnt=0;
    if(c1==c2){
        cout<<1;
        sum=1;
    }else{
        cout<<0;
    }
    if(sum==0){
        cout<<0<<0<<0;
        return 0;
    }
    if(s1[0]==s2[0]&& s1[1]==s2[1]){
        cout<<1;
        cnt=1;
    }
    if(cnt==0){
        cout<<0<<0<<0;
        return 0;
    }else{
        if(s1[2]<='C' && s2[2]<='C'){
            cout<<1;
            ans=1;
        }
        else if((s1[2]=='D'||s1[2]=='F')&& (s2[2]=='D' && s2[2]=='F')){
                    cout<<1;
                    ans=1;
                }else{
                    cout<<0;
                }
        }if(ans==1 && sum==1 && abs(char(s1[2])-char(s2[2]))==1){
            cout<<1;
        }else{
            cout<<0;
        }
    return 0;
    }
