#include<bits/stdc++.h>
using namespace std;
int f(char a,char b){
    if('A'<=a&&a<='C') a='0';
    else a='1';
    if('A'<=b&&b<='C') b='0';
    else b='1';
    if(a==b) return 1;
    else return 0;
}
int ff(char a,char b)
{
    if(a=='A'&&b=='B') return 1;
    if(a=='B'&&(b=='A'||b=='C')) return 1;
    if(a=='C'&&(b=='B')) return 1;
    if(a=='F'&&b=='D') return 1;
    if(a=='D'&&b=='F') return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<"0000";
    else{
        cout<<"1";
        if(s1[0]!=s2[0]||s1[1]!=s2[1]) {
            cout<<"000";
            return 0;
        }
        else cout<<"1";
        cout<<f(s1[2],s2[2])<<ff(s1[2],s2[2]);

    }
    return 0;
}
