#include <bits/stdc++.h>
using namespace std;
long long n,a,l,ans;
string s="",c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>c;
        for(long long i=1;i<=a;i++){
            s+=c;
        }
    }
    l=s.size();
    for(long long i=1;i<=l/2;i++){
        if(s[i-1]!=s[l-i]) ans++;
    }
    cout<<ans;
    return 0;
}
