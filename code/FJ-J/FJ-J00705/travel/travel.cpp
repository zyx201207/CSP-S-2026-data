#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Please return
#define AC 0
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a,b,c,d;
    a=(c1==c2);
    b=(s1[0]==s2[0]&&s1[1]==s2[1]);
    c=(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C');
    d=(abs(s1[2]-s2[2])==1);
    cout<<(a);
    cout<<(a&&b);
    cout<<(a&&b&&c);
    cout<<(a&&b&&c&&d);
    Please AC;
}

