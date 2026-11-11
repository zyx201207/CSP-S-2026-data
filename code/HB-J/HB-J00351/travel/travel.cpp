#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        ans+='1';
    }else {
        ans+='0';
    }
    if(b[0]==d[0]&&b[1]==d[1]&&ans[0]=='1'){
        ans+='1';
    }else{
        ans+='0';
    }
    if(b[2]>='D'){
        if(d[2]>='D'&&ans[1]=='1'){
            ans+='1';
        }else ans+='0';
    }else {
        if(d[2]<'D'&&ans[1]=='1'){
            ans+='1';
        }else ans+='0';
    }
    if(abs(b[2]-d[2])==1&&ans[2]=='1'){
        ans+='1';
    }else {
        ans+='0';
    }
    cout<<ans;
    return 0;
}



