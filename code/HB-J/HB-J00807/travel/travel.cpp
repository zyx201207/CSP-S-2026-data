#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;
string s1,s2,a1,a2;
//100
int main(){
    freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s1>>s2>>a1>>a2;
    if(s1==a1){
        cout<<1;
        if(a2[0]==s2[0]&&a2[1]==s2[1]){
            cout<<1;
           if((s2[2]<='C'&&a2[2]<='C')||(a2[2]>'C'&&s2[2]>'C')) cout<<1;
           else cout<<0;

        }else{
            cout<<0<<0;

        }
    }else{
        cout<<0<<0<<0;
    }
    if(s2[0]==a2[0]&&s2[1]==a2[1]&&abs(s2[2]-a2[2])==1&&(!(s2[2]=='C'&&a2[2]=='D')&&!(s2[2]=='D'&&a2[2]=='C'))) cout<<1;
        else cout<<0;
    return 0;
}
