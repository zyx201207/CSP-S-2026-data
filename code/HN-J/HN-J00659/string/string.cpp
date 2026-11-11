
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    vector<int>a(n+1);
    vector<char>c(n+1);
    vector<char>s;
    long long tota=0;
    long long mgcd=-1;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        if(mgcd==-1) {
            mgcd=a[i];
        } else {
            mgcd=__gcd(mgcd,(long long)a[i]);
        }
    }
    for(int i=1;i<=n;i++) {
        tota+=a[i]/mgcd;
        for(int j=1;j<=a[i]/mgcd;j++) {
            s.push_back(c[i]);
        }
    }
    //for(int i=0;i<tota;i++) {
    //    cout<<s[i];
    //}
    //cout<<'\n';
    int mid=(tota-1)/2+1;
    long long ans=0;
    for(int i=mid;i<tota;i++) {
        //cout<<i<<' '<<tota-i-1<<'\n';
        //cout<<s[i]<<' '<<s[tota-i-1]<<'\n';
        if(s[i]!=s[tota-i-1])ans++;
    }
    cout<<ans*mgcd;

}
