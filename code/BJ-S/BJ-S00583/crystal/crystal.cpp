#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
queue<int> q;
int now,cost;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    q.push(a[n]);
    now=n;
    int ans=-1;
    while(1){
        now--;
        if(now==0) break;
        int tmp=q.front();
        int delta=tmp-a[now];
        q.push(a[now]);
        cost+=delta;
        if(cost>m){
            q.pop();
            cost-=q.size()*(tmp-q.front());
        }
        ans=max(ans,(long long)q.size());
    }
    cout<<ans;
    return 0;
}
