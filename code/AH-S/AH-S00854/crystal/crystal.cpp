#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr)
const int N=500005;
int n;
long long m,a[N],pre[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    fast_io;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=a[i]+pre[i-1];
    int l=1,r=1;
    while(1){
        long long tmp=a[r]*(r-l+1)-(pre[r]-pre[l-1]);
        if(tmp<=m){
            while(a[r+1]==a[r]) r++;
            ans=max(ans,1ll*(r-l+1));
            if(r==n) break;
            r++;
        }
        else l++;
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
