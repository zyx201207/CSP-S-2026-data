#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
string s;

signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        string ls;
        cin>>ls;
        while(a--) s+=ls;
    }

    int sz=s.size();
    int cnt=0;

    for(int i=0;i<sz/2;i++){
        if(s[i]!=s[sz-i-1]) cnt++;
    }
    cout<<cnt;
return 0;
}
