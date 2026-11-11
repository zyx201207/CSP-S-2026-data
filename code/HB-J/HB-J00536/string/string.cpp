#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,ans;
char c;
deque<pair<ll,char>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>x>>c;
        q.push_back({x,c});
    }
    while(!q.empty()){
        if(q.size()==1){
            break;
        }
        pair<ll,char> l,r;
        l=q.front(),r=q.back();
        q.pop_back();
        q.pop_front();
        ll cnt=min(l.first,r.first);
        l.first-=cnt;
        r.first-=cnt;
        if(l.second!=r.second) ans+=cnt;
        if(l.first!=0) q.push_front(l);
        if(r.first!=0) q.push_back(r);
    }
    cout<<ans;
    return 0;
}
