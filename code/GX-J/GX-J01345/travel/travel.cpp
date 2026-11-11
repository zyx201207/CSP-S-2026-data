#include<bits/stdc++.h>
using namespace std;
char c1,s1;
long long c,s,cc,ss;
bool g,h,j;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c1>>cc>>ss>>s1;
    if(c==cc){
        cout<<1;
        g=true;
    }
    else cout<<0;

    if(g && s==ss){
        cout<<1;
        h=true;
    }
    else cout<<0;

    if(h){
        if(c1<='C' && s1<='C'){
            cout<<1;
            j=true;
        }
        else if(c1>='D' && s1>='D'){
            cout<<1;
            j=true;
        }
        else cout<<0;
    }
    else cout<<0;

    if(j){
        if(c1+1==s1 || s1+1==c1){
            cout<<1<<endl;
        }
        else cout<<0<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
