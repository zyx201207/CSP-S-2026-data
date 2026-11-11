#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],t[300010],ans[300010];
vector<ll>g;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll aa=1;aa<=n;aa++){
        memset(t,0,sizeof(t));
        g.clear();
        for(ll i=aa;i<=n;i++){
            if(t[a[i]]==0){
                g.push_back(a[i]);
                t[a[i]]++;
            }else{
                ll idx;
                for(ll j=0;j<g.size();j++){
                    if(g[j]==a[i]){
                        idx=j;
                        break;
                    }
                }
                for(ll j=g.size()-1;j>=idx;j--){
                    t[g[j]]--;
                    g.pop_back();
                }
                g.push_back(a[i]);
                t[a[i]]++;
            }
        }
        for(ll i=0;i<g.size();i++){
            ans[g[i]]++;
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
