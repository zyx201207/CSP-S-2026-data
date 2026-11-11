#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,ans;
ll a[N],sum[N],tot[27];char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    cin>>n;
    string s="";
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];++j) s+=c[i];
    }
    for(ll i=0;i<s.size();++i){
        if(i>s.size()-i-1) break;
        if(s[i]!=s[s.size()-i-1]) ++ans;
    }
    cout<<ans;
    return 0;
}