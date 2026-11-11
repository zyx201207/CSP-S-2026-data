#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m;
string c[N];
void solve(){
    cin>>n>>m;
    vector<ll>v(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(m==1){
            ll maxn=0;
        for(int i=0;i<n;i++){
            maxn=max(maxn,v[i]);
        }
        cout<<maxn;
    }else if(n==m){
        ll q=1;
        for(int i=1;i<n;i++){
                if(i==1){
                    q=v[i]|v[0];
                }else{
                    q=q|v[i];
                }

        }
        cout<<q;
    }else{
        cout<<0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
