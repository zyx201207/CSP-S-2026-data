#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum,ans;
map <int,int> cnt,v;
vector <int> use;
void dfs(int s){
    if(!s){
        int now=0;
        for(int x:use){
            if(cnt[x]>1) now=max(now,cnt[x]);
        }
        ans=max(ans,now);
        return;
    }
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]<2){
            if(v[a[i]]){
                for(int &i:use){
                    if(i==a[i]) i=0;
                }
            }
        }
        cnt[a[i]++]--;
        cnt[a[i]]++;
        use.push_back(a[i]);
        dfs(s-1);
        if(cnt[a[i]]<2){
            if(v[a[i]]){
                for(int &i:use){
                    if(i==a[i]){
                        i=0;
                        break;
                    }
                }
            }
        }
        cnt[a[i]--]--;
        cnt[a[i]]++;
        use.push_back(a[i]);
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        cnt[a[i]]++;
        use.push_back(a[i]);
    }
    sort(a+1,a+n+1);
    if(m>=n*a[n]-sum){
        cout<<n;
        return 0;
    }
    dfs(m);
    cout<<ans;
    return 0;
}
