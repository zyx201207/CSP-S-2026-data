#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5,mod=1e9+7,INF=1e18;
int a[N],s[N],ans[N],b[N];
int n,m;
int mine[N],maxx[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    memset(mine,0x3f,sizeof(mine));
    memset(maxx,-0x3f,sizeof(maxx));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mine[a[i]]=min(mine[a[i]],i);
        maxx[a[i]]=max(maxx[a[i]],i);
    }
    for(int i=1;i<=m;i++){
        s[mine[i]]-=1;
        s[maxx[i]]+=1;
    }
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+s[i];
        ans[a[i]]=max(ans[a[i]],b[i]+i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
