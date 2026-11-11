#include <bits/stdc++.h>

#define c(x) cout<<x<<endl
#define inf 0x3f3f3f3f
#define int long long
#define fet(x) const int fet=x

using namespace std;

fet(2e5+10);

int a[fet];
char c[fet];
int ans;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,all=0; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        all+=a[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            int del=min(a[l],a[r]);
            if(a[l]==del){
                l++,a[r]-=del;
            }else{
                r--,a[l]-=del;
            }
        }else{
            int del=min(a[l],a[r]);
            if(a[l]==del){
                l++,a[r]-=del;
            }else{
                r--,a[l]-=del;
            }
            ans+=del;
        }
    }
    c(ans);
    return 0;
}
