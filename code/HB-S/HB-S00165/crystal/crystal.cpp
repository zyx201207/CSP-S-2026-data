/*
CSP-S2 2026
Question.A
Usage Time: 66 min
Expectation Score: 60 points
Maxinum Score:100 points
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int maxN=5e5+10;
ll n,ans=1;
ll m;
ll a[maxN],mn;
deque<ll> q;
inline ll s(ll x){
    return x-mn;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    mn=a[1];
    ll delta=0,lst;
    for(int i=1;i<=n;i++){
        q.push_back(a[i]);
        lst=a[i];
        delta=delta+(q.back()-a[i-1])*((ll)q.size()-1);
        //cout<<delta<<" ";
        while(!q.empty()&&delta>m){
            delta-=q.back()-q.front();
            q.pop_front();
        }
        //cout<<delta<<" ";
        ans=max(ans,(ll)q.size());
    }
    cout<<ans;
    return 0;
}