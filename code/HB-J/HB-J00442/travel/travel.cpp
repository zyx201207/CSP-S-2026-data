#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    char x,y;
    cin>>c1>>s1>>x>>c2>>s2>>y;
    bool a=0,b=0,c=0,d=0;
    if(c1==c2) a=1;
    if(a==1&&s1==s2) b=1;
    if(b==1){
        if(x<'D'&&y<'D') c=1;
        else if(x>='D'&&y>='D') c=1;
    }
    if(c==1&&abs(x-y)==1) d=1;
    cout<<a<<b<<c<<d;
    return 0;
}
