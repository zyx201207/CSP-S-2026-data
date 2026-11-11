#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],pos,l,s,r,ans,t;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    l=1;
    r=n;
    pos=0;
    while(pos<=s/2&&l<r){
        t=min(a[l],a[r]);
        if(c[l]!=c[r]){
            ans+=t;
        }
        pos+=t;
        a[l]-=t;
        a[r]-=t;
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
