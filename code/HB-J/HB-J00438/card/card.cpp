#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll n,m;
map<ll,ll>mp;
void solve(){
    cin>>n>>m;
    vector<ll>v(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]=0;
    }
    ll q=n;
    ll w=0;

    while(q--){
        vector<ll>b(m+1,0),c(m+1,0);
        for(int i=n-q;i<n;i++){
            if(b[v[i]]==0){
                b[v[i]]=1;
                c[v[i]]=i;
            }else{
                ll r=c[v[i]];
                for(int j=r;j<=i;j++){
                    b[v[j]]=0;
                }
                c[v[i]]=i;
                b[v[i]]=1;
            }
        }
        for(int i=0;i<b.size();i++){
            if(b[v[i]]==1){
                mp[v[i]]++;

            }
        }


         w++;
    }
    for(auto i:mp){
        cout<<i.second<<" ";
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
