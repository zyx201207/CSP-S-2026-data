#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>s1>>c>>d>>s2;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(b!=d){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if((s1<='C'&&s2>'C')||(s1>'C'&&s2<='C')){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(s1+1==s2||s2+1==s1)cout<<1;
    else cout<<0;
    return 0;
}
