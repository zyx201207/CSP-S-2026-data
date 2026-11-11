#include<bits/stdc++.h>
using namespace std;
    string c1,c2,s1,s2;
int tod(string s){
int len=s.size(),le=len;
int ans=0;
while(len+1 && len){
    len--;
    ans=ans*10+(s.[le-len-1]-'0');
}return ans;
}
int main(){
    freopen("travel.in","t",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    int c=tod(c1),cc=tod(c2),s=tod(s1[0])*10+tod(s1[1]),ss=tod(s2[0])*10+tod(s2[1]);
    if(c==cc){
        cout<<1;
    }else{
    cout<<0;
    }if(s==ss){
        cout<<1;
    }else{
    cout<<0;
    }if(s==ss && s1[2]>='A' && s1[2]<='C'&&s2[2]>='A' && s2[2]<='C'||s==ss && s1[2]>='D' && s1[2]<='F'&&s2[2]>='D' && s2[2]<='F'){
        cout<<1;
    }else{
    cout<<0;
    }if(c==cc && s==ss && s1[2]=='A' && s2[2]=='B' || c==cc && s==ss && s1[2]=='B' && s2[2]=='C' || c==cc && s==ss && s1[2]=='D' && s2[2]=='F' || c==cc && s==ss && s1[2]=='B' && s2[2]=='A' || c==cc && s==ss && s1[2]=='C' && s2[2]=='B' || s1[2]=='F' && s2[2]=='D'){
    cout<<1;
    }else{
    cout<<0;

    }
    return 0;
}
