#include <bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
int n;
ll a[N];
ll sum=0;
string s=" ",c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++){
            s+=c;
        }
        sum+=a[i];
    }
    ll ans=0;
    for(ll i=1;i<=sum;i++){
        ll j=sum-i+1;
        if(i>=j) break;
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
