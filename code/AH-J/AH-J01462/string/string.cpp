#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
signed main(){
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char a;
        cin>>a;
        for(int j=1;j<=x;j++){
            s=s+a;
        }
    }
    string s2="";
    for(int i=s.size()-1;i>=0;i--){
        s2+=s[i];
    }
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s2[i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}
