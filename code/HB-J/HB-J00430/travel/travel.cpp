#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
const int N=2e5+12;
void solve(){
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    ll flag=0;
    if(c1==c2) flag=1,cout<<1;
    else cout<<0;
    if(flag==1&&s1[0]==s2[0]&&s1[1]==s2[1]) flag=2,cout<<1;
    else cout<<0;
    if(flag==2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))) flag=3,cout<<1;
    else cout<<0;
    if(flag==3&&abs(s1[2]-s2[2])==1) cout<<1;
    else cout<<0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    while(t--){
        solve();
    }
    return 0;
}
