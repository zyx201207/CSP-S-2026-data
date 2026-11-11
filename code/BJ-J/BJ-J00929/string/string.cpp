#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    vector<char> s;
    ll ans=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        int ai;cin>>ai;
        char ci;cin>>ci;
        sum+=ai;
        while(ai--) s.push_back(ci);
    }
    for(int i=0;i<sum/2;i++){
        if(s[i]!=s[sum-i-1])
            ++ans;
    }
    cout<<ans;
    return 0;
}
