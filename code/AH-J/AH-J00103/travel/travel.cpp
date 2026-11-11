#include <bits/stdc++.h>
using namespace std;

string a,b,c,d;
char e,f;

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    e=b.back();
    f=d.back();
    b.pop_back();
    d.pop_back();
    if (a==c) cout<<"1";
    else cout<<"0";
    if (a==c&&b==d) cout<<"1";
    else cout<<"0";
    if (a==c&&b==d&&((e<='C'&&f<='C')||(e>='D'&&f>='D'))) cout<<"1";
    else cout<<"0";
    if (e>f) swap(e,f);
    if (a==c&&b==d&&((e=='A'&&f=='B')||(e=='B'&&f=='C')||(e=='D'&&f=='F'))) cout<<"1";
    else cout<<"0";
    return 0;
}
