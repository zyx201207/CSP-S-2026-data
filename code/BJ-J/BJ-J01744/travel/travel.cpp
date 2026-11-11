#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+7;

int T,n,m;
signed main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) {
        cout<<1;
        if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>=3&&s2[2]-'A'>=3)) {
            cout<<1;
            int a=s1[2]-'A',b=s2[2]-'A';
            if(a==2&&b==3) cout<<0;
            else if(a==3&&b==5) cout<<1;
            else if(abs(a-b)==1) cout<<1;
            else cout<<0;
        }
        else {
                cout<<"00";
                return 0;
        }
    }
    else cout<<"000";
    return 0;
}
