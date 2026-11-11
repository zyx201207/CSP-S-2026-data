#include<bits/stdc++.h>
using namespace std;
int n,t,cnt=0,ls;
char c;
string s;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t>>c;
        for(int i=1;i<=t;i++) {
            s+=c;
        }
    }
    ls=s.size();
    for(int i=0;i<ls/2;i++) {
        if(s[i]!=s[ls-i-1]) {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
