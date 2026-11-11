#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,ans=1;
ll m;
vector<ll> v;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    v.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=n-1;i>=0;i--){
        int cur=1,mi=m;
        for(int j=i-1;j>=0;j--){
            if((mi-v[i]+v[j])>=0){
                mi=mi-v[i]+v[j];
                cur++;
            }
            else{
                break;
            }
        }
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';
    return 0;
}