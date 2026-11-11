/*

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],maxn,v[N],v2[N],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
    maxn=log2(maxn);
    for(int j=maxn+1;j>=1;j--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(v[i]) continue;
            cnt+=((a[i]>>(j-1))&1);
        }
        if(cnt>=m){
            ans+=1<<(j-1);
            for(int i=1;i<=n;i++){
                if(v[i]) continue;
                if(!((a[i]>>(j-1))&1)) v[i]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}