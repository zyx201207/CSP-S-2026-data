#include<bits/stdc++.h>
using namespace std;
vector<int> g[32];
int a[200005];
int cnt[32],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=30;j++){
            if(a[i]&(1<<j)) g[j].push_back(i),cnt[j]++;
        }
    }
    for(int k=30;k>=0;k--){
        if(cnt[k]>=m){
            ans+=(1<<k);
            memset(cnt,0,sizeof cnt);
            for(int j=0;j<k;j++){
                g[j].resize(0);
            }
            for(int i=0;i<g[k].size();i++){
                for(int j=0;j<k;j++){
                    if(a[g[k][i]]&(1<<j)) g[j].push_back(g[k][i]),cnt[j]++;
                }
            }
        }
    }
    cout<<ans;
}
