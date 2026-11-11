#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
bool f1,f2,f3,f4;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if (a==c) f1=true;
    if (f1 && b[0]==d[0] && b[1]==d[1]) f2=true;
    if (f2 && ((b[2]<='C' && d[2]<='C') || (b[2]>='D' && d[2]>='D'))) f3=true;
    if (f3 && (b[2]+1==d[2] || d[2]+1==b[2] || (b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D'))) f4=true;
    cout<<f1<<f2<<f3<<f4;
    return 0;
}