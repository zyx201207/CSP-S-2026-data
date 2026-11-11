#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.in","r",stdout);
    int n;
    cin>>n;
    string s = "";
    for(int i = 1;i<=n;i++){
        int t;
        char a;
        cin>>t>>a;
        while(t--){
            s+=a;
        }
    }
    int ans = 0;
    for(int i = 0;i<s.size()/2;i++){
        if(s[i] == s[s.size()-i-1])continue;
        else ans++;
    }
    cout<<ans;
    return 0;
}
