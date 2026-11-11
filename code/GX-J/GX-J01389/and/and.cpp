#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],cnt[35],ans;
vector <int> ok[35];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;(1<<j)<=a[i];j++){
            if((1<<j)&a[i]){
                cnt[j]++;
                ok[j].push_back(i);
            }
        }
    }
    for(int i=log2(a[n]);i>=0;i--){
        if(cnt[i]>=m){
            ans+=1<<i;
            for(int j=i-1;j>=0;j--){
                cnt[j]=0;
                ok[j]=ok[34];
            }
            for(int j:ok[i]){
                for(int k=i-1;k>=0;k--){
                    if((1<<k)&a[j]){
                        cnt[k]++;
                        ok[k].push_back(j);
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
