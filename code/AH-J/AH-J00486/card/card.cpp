#include<bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
}
#define int long long
const int N=5e5+10;
int a[N],cnt[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int l=1;l<=n;l++){
        vector<int> p;
        for(int i=l;i<=n;i++){
            if(!p.empty()){
                auto it=lower_bound(p.begin(),p.end(),a[i]);
                // cout<<*it<<" ";
                if(*it!=a[i]){
                    p.push_back(a[i]);
                }else{
                    p.erase(it+1,p.end());
                    // p.push_back(a[i]);
                }
            }else{
                p.push_back(a[i]);
                // cout<<"e ";
            }
        }
        // cout<<"\n";
        for(auto& x:p){
            // cout<<x<<" ";
            cnt[x]++;
        }
        // cout<<"\n";
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    cout<<"\n";
    return;
}
