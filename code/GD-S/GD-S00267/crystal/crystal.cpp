#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
queue<int>q;
int a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        while(!q.empty()){
            int j=q.front();
            if(m<a[i]*(i-j)-sum[i-1]+sum[j-1]) q.pop();
            else break;
        }
        q.push(i);
        ans=max(ans,(int)q.size());
    }
    cout<<ans;
    return 0;
}