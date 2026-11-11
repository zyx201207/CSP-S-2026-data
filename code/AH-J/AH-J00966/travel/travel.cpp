#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
    }
    string s=b.substr(0,2);
    string t=d.substr(0,2);
    if(a==c&&s==t){
        cout<<1;
    }else{
        cout<<0;
    }
    s=b.substr(2,1);
    t=d.substr(2,1);
    char p=s[0];
    char q=t[0];
    if((a==c&&s==t)&&(p<='C'&&q<='C'||p>='D'&&p<='E'&&q<='E'&&q>='D')){
        cout<<1;
    }else{
        cout<<0;
    }
    if((a==c&&s==t)&&(p<='C'&&q<='C'||p>='D'&&p<='E'&&q<='E'&&q>='D')&&(p+1==q||q+1==p)){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
