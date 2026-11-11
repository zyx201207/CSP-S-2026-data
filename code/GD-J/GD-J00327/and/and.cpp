#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,ans[N],tmp[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>ans[i];
    int len=n;
    for(int j=29;j>=0;j--){
        int ct1=0;
        for(int i=1;i<=len;i++)
            if((ans[i]>>j&1))
                tmp[++ct1]=ans[i];
        if(ct1>=m){
            for(int i=1;i<=ct1;i++) ans[i]=tmp[i];
            len=ct1;
        }
    }
    int res=(1<<30)-1;
    for(int i=1;i<=m;i++)
        res=(res&ans[i]);
    cout<<res;
    return 0;
}