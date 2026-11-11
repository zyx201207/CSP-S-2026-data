#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int cnt=0;
    if(c1==c2){
        cout<<1;
        cnt++;
    }else
        cout<<0;
    if(cnt==1&&(s1[0]==s2[0]&&s1[1]==s2[1])){
        cout<<1;
        cnt++;
    }else
        cout<<0;
    s1[2]-=65;
    s2[2]-=65;
    if(cnt==2&&((s1[2]<=2&&s2[2]<=2)||(s1[2]>=3&&s2[2]>=3))){
        cout<<1;
        cnt++;
    }else
        cout<<0;
    if(cnt==3&&((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)))
        cout<<1;
    else
        cout<<0;
    return 0;
}