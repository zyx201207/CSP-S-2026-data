#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1>="01"&&c1<="017"&&c2>="01"&&c2<="017"){
        cout<<0;
    }else{
        cout<<1;
    }
    if(c1>="01"&&c1<="017"&&c2>="01"&&c2<="017"&&c1==c2){
        cout<<0;
    }else{
        cout<<1;
    }
    if(c1>="01"&&c1<="017"&&c2>="01"&&c2<="017"&&c1+c2!=c2){
        cout<<0;
    }else{
        cout<<1;
    }
    if(s1!=s2&&s2=="01B"){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
