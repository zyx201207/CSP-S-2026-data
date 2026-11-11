#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    if(c!=cc){
        cout<<"0000";
        return 0;
    }
    if(s[0]!=ss[0]||s[1]!=ss[1]){
        cout<<"1000";
        return 0;
    }
    if((s[2]<='C'&&ss[2]>='D')||(s[2]>='D'&&ss[2]<='C')){
        cout<<"1100";
        return 0;
    }
    if(abs(int(s[2])-int(ss[2]))==1) cout<<"1111";
    else cout<<"1110";
    return 0;
}
