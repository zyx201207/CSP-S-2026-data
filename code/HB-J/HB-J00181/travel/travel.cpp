#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(ll)(b);++i)
const int maxn=5e5+10;

int main(){
#if 1
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        cout<<"1";
        if(s2[0]==s4[0]&&s2[1]==s4[1])
        {
            cout<<"1";
            if( !(s2[2]>='D') ^ (s4[2]>='D') )
            {
                cout<<"1";
                cout<<bool(abs((int)s2[2]-s4[2])==1);
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}