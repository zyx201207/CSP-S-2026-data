#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010],m,l[500010],mp[500010],k[500010],ans[500010],mpp[500010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(mpp[a[i]]){
            l[i]=k[a[i]];
        }
        k[a[i]]=i;
        mpp[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        ans[a[n]]++;
        map<int,int> mp;
        mp[a[n]]=1;
        for(int j=n;j>=i;j--){
            if(l[j]&&l[j]>=i){
                j=l[j];
                if(!mp[a[j]]){
                    ans[a[j]]++;
                    mp[a[j]]=1;
                }
            }
            else{
                if(mp[a[j]]){
                    continue;
                }
                ans[a[j]]++;
                mp[a[j]]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
