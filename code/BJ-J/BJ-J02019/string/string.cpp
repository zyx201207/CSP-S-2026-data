#include <bits/stdc++.h>
using namespace std;
long long n,ans,a[200005];
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    for(long long l=1,r=n;l<=r;){
        long long len=min(a[l],a[r]);
        a[l]-=len;
        a[r]-=len;
        if(ch[r]!=ch[l]){
            ans+=len;
        }
        if(a[l]<=0){
            l++;
        }
        if(a[r]<=0){
            r--;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
