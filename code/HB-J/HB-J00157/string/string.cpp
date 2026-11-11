#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],l,r,ans;char s[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;l=1,r=n;
    for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
    while(l<r){
        if(s[l]!=s[r]){
            if(a[l]>a[r]) ans+=a[r],a[l]-=a[r--];
            else ans+=a[l],a[r]-=a[l++];
        }else{
            if(a[l]>a[r]) a[l]-=a[r--];
            else a[r]-=a[l++];
        }
    }
    cout<<ans;
    return 0;
}
