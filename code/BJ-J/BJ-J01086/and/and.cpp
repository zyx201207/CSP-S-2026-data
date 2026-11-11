#include<bits/stdc++.h>
#define int long long
#define fr(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define fd(i,r,l) for(int (i)=(r);(i)>=(l);(i)--)
using namespace std;

const int N=2e5+10,B=30+5;
priority_queue<int>q[B];

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    fr(i,1,n){
        int x;cin>>x;
        fr(b,0,30)if(x&(1<<b))q[b].push(x);
    }
    int ans=0;
    fd(b,30,0)if(q[b].size()>=m){
        int cnt=m-1,tmp=q[b].top();q[b].pop();
        while(cnt--)tmp&=q[b].top(),q[b].pop();
        ans=max(ans,tmp);
    }
    cout<<ans<<'\n';
    return 0;
}