#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],MAX=0;
priority_queue<ll,vector<ll>,greater<ll> > pq;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>=5000){
        int d=a[2]-a[1];
        ll sum=0,pre;
        int i;
        for(i=1;sum<=m;i++){
            sum+=i*d;
        }
        cout<<i-1;
        return;
    }
    sort(a+1,a+1+n,greater<ll>());
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            pq.push(abs(a[i]-a[j]));
            //cout<<abs(a[i]-a[j])<<' ';
        }
        ll sum=0,cnt=0;
        while(!pq.empty()&&sum<=m){
            sum+=pq.top();
            pq.pop();
            cnt++;
        }
        MAX=max(MAX,cnt);
    }
    cout<<MAX;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
