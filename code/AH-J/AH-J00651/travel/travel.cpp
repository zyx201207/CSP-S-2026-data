#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    string t1=s1.substr(0,2);
    string t2=s2.substr(0,2);
    if(t1==t2&&c1==c2)cout<<1;
    else cout<<0;
    char a=s1[2],b=s2[2];
    if(t1==t2&&c1==c2&&(a>='A'&&a<='C'&&b>='A'&&b<='C'||a>='D'&&a<='F'&&b>='D'&&b<='F')){
            cout<<1;
            if(a+1==b||b+1==a||a=='D'&&b=='F'||a=='F'&&b=='D')cout<<1;
            else cout<<0;
    }else cout<<"00";
    return 0;
}
