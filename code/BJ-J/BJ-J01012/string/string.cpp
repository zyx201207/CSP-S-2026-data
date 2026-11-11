#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int n,a[N];
ll ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        char c;
        cin>>c;
        for(int j=1;j<=a[i];j++)s+=c;

    }
    ll len=s.size();
    for(ll i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])ans++;

    }

    cout<<ans;
    return 0;
}
