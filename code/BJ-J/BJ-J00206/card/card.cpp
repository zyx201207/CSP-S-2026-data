#include<bits/stdc++.h>
using namespace std;
#define int long long
int h[500005],a[500005],k[500005],ans[500005];
vector<long long> v[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(h,-1,sizeof h);
    v[n].push_back(a[n]);
    ans[a[n]]++;
    h[a[n]]=n;
    for(int i=n-1;i>=1;i--){
        if(h[a[i]]==-1){
            for(auto k:v[i+1]){
                v[i].push_back(k);
                ans[k]++;
                //cout<<k<<" ";
            }
            v[i].push_back(a[i]);
            ans[a[i]]++;
            //cout<<a[i]<<endl;
        }
        else {
            for(auto k: v[h[a[i]]]){
                v[i].push_back(k);
                ans[k]++;
                //cout<<k<<" ";

            }
            //cout<<endl;
        }
        h[a[i]]=max(h[a[i]],i);
        //cout<<dp[i]<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    //cout<<endl;
    return 0;
}
