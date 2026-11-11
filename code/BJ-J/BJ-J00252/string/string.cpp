#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+45;
int a[N];
char c[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }

    ll li=1,ri=n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[li]==0) li++;
        if(a[ri]==0) ri--;
        int x=min(a[li],a[ri]);
        if(c[li]!=c[ri]) ans+=x;
        a[li]-=x;
        a[ri]-=x;
    }
    cout<<ans;
}
