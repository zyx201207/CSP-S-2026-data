#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c1,s1,c2,s2;
    char a1,a2;
    cin>>c1>>s1>>a1>>c2>>s2>>a2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s1==s2){
        cout<<1;
    }else{
        cout<<0;
    }
    if((s1==s2)&&((a1<='C'&&a2<='C')||(a1>'C'&&a2>'C'))){
        cout<<1;
    }else{
        cout<<0;
    }
    if((s1==s2)&&(abs(a1-a2)==1)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}

