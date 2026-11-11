#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans[3];
void solve(){
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1]){
        cout<<1;
      if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout<<1;
        int a=s1[2]-'C';
        int b=s2[2]-'C';
        if((a>0 && b>0)||(a<=0 && b<=0)){
            cout<<1;
            if(abs(a-b)==1)cout<<1;
            else cout<<0;
        }else cout<<"00";
      }else cout<<"000";
    }else cout<<"0000";
    }
int main(){
    ios::sync_with_stdio(false);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    solve();
    return 0;
    }
