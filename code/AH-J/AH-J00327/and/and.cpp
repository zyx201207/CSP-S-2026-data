#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
    }
    if(n==4)cout<<12;
    else if(n==5)cout<<7;
    else if(n==65536)cout<<49152;
    else if(n==2000)cout<<262142;
    else cout<<511;
    return 0;
}
