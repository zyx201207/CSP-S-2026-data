#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[200005]={0};
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c[i];
        b[i]=b[i-1]+a;
    }
    ll l=1,r=b[n],p=1,q=n;
    while(l<=r){
        if(l>b[p])p++;
        if(r<=b[q-1])q--;
        if(c[p]!=c[q])
            ans++;
        l++,r--;
    }
    cout<<ans;
    return 0;
}
