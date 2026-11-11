#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t,n=0;
    cin>>t;
    string s;
    while(t--){
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++) s+=c;
        n+=x;
    }
    int ans=0;
    for(int i=0;i*2<=n;i++){
        if(s[i]!=s[n-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
