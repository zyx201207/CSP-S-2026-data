#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N],maxn[N];
void solve(){
    cin>>n>>m;
    vector<ll>v(n+1,0),d(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        d[i]=v[i]-v[i-1];
    }

        for(int i=2;i<=n;i++){
            a[v[i]]++;
        }
        while(m){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]&&d[i]*a[v[i-1]]<=m){
                m=m-d[i]*a[v[i-1]];
                a[v[i]]+=a[v[i-1]];
                a[v[i-1]]=0;
            }
        }

        break;

    }
    ll q=0;
    for(int i=1;i<=n;i++){
        q=max(q,a[v[i]]);
    }
    cout<<q+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll _=1;
    while(_--)solve();
    return 0;
}
