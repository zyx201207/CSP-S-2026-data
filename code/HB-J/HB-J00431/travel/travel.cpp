#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2,c1,c2,s1a,s2a;
char a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    s1a+=s1[0];
    s1a+=s1[1];
    s2a+=s2[0];
    s2a+=s2[1];
    a=s1[2];
    b=s2[2];
    if(c1==c2) {
        cout<<1;
        if(s1a==s2a) {
                cout<<1;
        if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')||(a=='F'||a=='D')&&(b=='D'||b=='F')){
            cout<<1;
        if(a>b)swap(a,b);
            if((a+1)==b&&b!='D'||b=='F'&&a=='D')cout<<1;
            else cout<<0;
           }
        else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
