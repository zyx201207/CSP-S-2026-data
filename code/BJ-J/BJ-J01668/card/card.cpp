#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];int dis[500005],ans[500005];int cnt[500005],cnt1[500005];
vector<int>g[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt1[a[i]]++;
        g[a[i]].push_back(i);
        dis[i]=1;
    }
    int b=0;
    for(int i=1;i<=n;i++){
        b+=dis[i];
        if(cnt[a[i]]+1!=cnt1[a[i]]){
            dis[i]-=b;
            cnt[a[i]]++;
            dis[g[a[i]][cnt[a[i]]]]+=b;
            b=0;
        }
        ans[a[i]]=max(ans[a[i]],b);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
