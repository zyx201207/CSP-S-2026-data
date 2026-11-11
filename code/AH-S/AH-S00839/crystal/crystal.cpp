#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn=1,ans;
int a[500005],cnt;
queue<int>q;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q.push(i);
        ans+=cnt*(a[i]-a[i-1]);
        cnt++;
        while(ans>m){
            ans-=a[i]-a[q.front()];
            cnt--;
            q.pop();
        }maxn=max(maxn,cnt);
    }cout<<maxn;
    return 0;
}
