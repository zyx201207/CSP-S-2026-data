#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500007],ans[500007]={0};
bool cnt[500007],p[500007],xz;
vector<ll> same[500007];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    xz=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        same[a[i]].push_back(i);
        if(i>1){
            if(a[i]<a[i-1]) xz=0;
        }
    }
    for(ll i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        for(ll j=i;j<=n;j++){
            for(ll k=0;k<same[a[j]].size();k++){
                if(same[a[j]][k]>a[j]) break;
                if(same[a[j]][k]==a[j]&&!cnt[same[a[j]][k]]){
                    for(ll l=same[a[j]][k];l<j;l++){
                        cnt[l]=1;
                    }
                }
            }
        }
        for(ll j=i;j<=m;j++){
            if(!cnt[j]&&!p[j]){
                ans[j]++;
            }
        }
    }
    for(ll i=1;i<=m;i++){
        if(i==m){
            cout<<n;
            continue;
        }
        ll res=0;
        for(ll j=1;j<=n;j++){
            if(a[j]==i) res=max(res,ans[j]);
        }
        cout<<res<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}//please let me AC!
