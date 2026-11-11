#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int id,c;
};
int n,m,a[500010],b[100010],c[500010],ac[500010],ans,sum;
deque<node> q;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(q.empty()==false){
            sum+=(q.size())*(a[i]-a[i-1]);
        }
        q.push_back({i,a[i]});
        while(sum>m){
            sum-=a[i]-q.front().c;
            q.pop_front();
        }
        int len=q.size();
        ans=max(ans,len);
    }
    cout<<ans;
    return 0;
}
