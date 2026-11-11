#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char s,t;
    cin>>a>>c>>s>>b>>d>>t;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    else {
        cout<<1;
        if(c==d){
            cout<<1;
            if((s>='A'&&s<='C'&&t>='D'&&t<='F')||(s>='D'&&s<='F'&&t>='A'&&t<='C'))cout<<0;
            else cout<<1;
        }
        else cout<<"00";
        if((s>='A'&&s<='C'&&t>='D'&&t<='F')||(s>='D'&&s<='F'&&t>='A'&&t<='C')){
            cout<<0;
            return 0;
        }
        if(s>='A'&&s<='C'){
            if(t+'1'==s-'0'||t-'1'==s-'0')cout<<1;
            else cout<<0;
        }
        else if(s=='D'||s=='F'){
            if(t+'2'==s-'0'||t-'2'==s-'0')cout<<1;
            else cout<<0;
        }
    }
    return 0;
}
