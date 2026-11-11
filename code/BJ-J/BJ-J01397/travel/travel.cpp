#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,ans="";
    cin>>a>>b>>c>>d;
    if(a==c)ans+='1';
    else{
        cout<<"0000";
        return 0;
    }
    string b1=b.substr(0,2),d1=d.substr(0,2);
    if(b1==d1)ans+='1';
    else{
        cout<<"1000";
        return 0;
    }
    if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
        if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
            ans+='1';
        }else{
            cout<<"1100";
            return 0;
        }
    }else{
        if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
            cout<<"1100";
        }else{
            ans+='1';
        }
    }
    if(d[2]+1==b[2]||d[2]==b[2]+1){
        ans+='1';
    }else{
        cout<<"1110";
        return 0;
    }
    cout<<ans;
    return 0;
}
