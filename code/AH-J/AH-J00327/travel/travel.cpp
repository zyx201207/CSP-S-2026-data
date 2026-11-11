#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1,s2,s3,s4;
    int f=1,f1=1,f2=1;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
    }else{
        cout<<0;
        f=0;
    }
    if(f==1&&s2[0]==s4[0]&&s2[1]==s4[1]){
        cout<<1;
    }else{
        cout<<0;
        f1=0;
    }
    if(f1==1&&((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C'))){
        cout<<1;
    }else{
        cout<<0;
        f2=0;
    }
    if(f2==1&&(s2[2]-s4[2]==1&&s2[2]!='D')||(s4[2]-s2[2]==1&&s4[2]!='D')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
