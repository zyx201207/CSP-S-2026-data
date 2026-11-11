#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        ans+='1';
    }
    else{
        ans+="0000";
        cout<<ans<<'\n';
        return 0;
    }
    if(r2[0]==x2[0]&&r2[1]==x2[1]){
        ans+='1';
    }
    else{
        ans+="000";
        cout<<ans<<'\n';
        return 0;
    }
    if((r2[2]>='A'&&r2[2]<='C'&&x2[2]>='A'&&x2[2]<='C')||(r2[2]>='D'&&r2[2]<='F'&&x2[2]>='D'&&x2[2]<='F')){
        ans+='1';
    }
    else{
        ans+="00";
        cout<<ans<<'\n';
        return 0;
    }
    if(abs(r2[2]-x2[2])==1){
        ans+='1';
    }
    else{
        ans+="0";
        cout<<ans<<'\n';
        return 0;
    }
    cout<<ans<<'\n';
    return 0;
}
