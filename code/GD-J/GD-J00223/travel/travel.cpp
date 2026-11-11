#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
#define ls (p<<1)
#define rs (ls|1)
const int N=2e6+10;
string s1,s2,s3,s4;
int ans[4];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<"1";
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            cout<<"1";
            if(s2[2]<='C'&&s4[2]<='C'){
                cout<<"1";
                if(s2[2]>s4[2])swap(s2[2],s4[2]);
                if(s2[2]=='A'&&s4[2]=='C'){
                    cout<<0;return 0;
                }
                else{
                    cout<<1;return 0;
                }
            }
            else if(s2[2]>='D'&&s4[2]>='D'){
                cout<<"11";return 0;
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    // cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<"\n";
    return 0;
}