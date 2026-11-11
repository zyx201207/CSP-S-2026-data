#include<bits/stdc++.h>
using namespace std;
bool f=1;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a1, a2, b1, b2;
    cin>>a1>>a2>>b1>>b2;
    f*=(a1==b1);
    cout<<(a1==b1);
    int x=(a2[0]-'0')*10+a2[1]-'0';
    int y=(b2[0]-'0')*10+b2[1]-'0';
    cout<<(x==y&&a1==b1);
    f*=(x==y);
    char a=a2[2], b=b2[2];
    if(!((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='C'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='E')||(a=='E'&&b=='D'))){
        f=0;
    }
    cout<<(((a<='C'&&b<='C')||(a>='D'&&b>='D'))&&x==y&&a1==b1);
    cout<<f;
    return 0;
}
