#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],ans,n,m,mp[41],maxx,h[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int p=a[i],cnt=1;
        while(p!=0){
            if(p&1){
                mp[cnt]++;
            }
            cnt++;
            p>>=1;
        }
        maxx=max(maxx,cnt);
    }
    for(int i=maxx;i>=1;i--){
        if(mp[i]<m){
            continue;
        }
        ans+=1<<(i-1);
        for(int j=1;j<=n;j++){
            if(h[j]){
                continue;
            }
            if(((1<<(i-1))&a[j])==0){
                h[j]=1;
                int p=a[j],cnt=1;
                while(p!=0){
                    if(p&1){
                        mp[cnt]--;
                    }
                    cnt++;
                    p>>=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
