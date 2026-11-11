#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
queue<int> q;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0,sum=0;
    for (int i=1;i<=n;i++){
        q.push(a[i]);
        sum+=a[i];
        int tem=q.size();
        while (q.size()*a[i]-sum>m){
            sum-=q.front();
            q.pop();
        }
        tem=q.size();
        ans=max(ans,tem);
    }
    cout<<ans<<'\n';
    return 0;
}
