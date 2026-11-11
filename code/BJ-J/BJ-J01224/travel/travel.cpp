#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    int c,d;
    char e,f;
    cin>>a>>c>>e>>b>>d>>f;
    e=int(e);
    f=int(f);
    if(a==b){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a==b&&c==d){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a==b&&c==d&&(e<=67 && f<=67) || (e>67 && f>67)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a==b&&c==d&&((e<=67 && f<=67) || (e>67 && f>67)) && (((e==f+1) || (e==f-1))||(e+f==138))){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
