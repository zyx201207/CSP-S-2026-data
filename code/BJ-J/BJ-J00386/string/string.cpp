#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="0";
    int n,gcd=0,a[200005];
    long long ans=0ll;
    char c[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        gcd=__gcd(gcd,a[i]);

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i]/gcd;j++){
            s+=c[i];
        }
    }
    for(int i=1;i<=s.size()-1;i++){
        if(s[i]!=s[s.size()-i]){
            ans++;
        }
    }
    ans=ans/2*gcd;
    cout<<ans;
    return 0;
}
