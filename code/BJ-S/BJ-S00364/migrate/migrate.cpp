#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],f;
ll m;
struct node{
    ll zl,ti;
};
vector<node> ve[100005];
int cnt[200005];
bool ch(ll l,ll r){
    int Min=0,tmp=m;
    for(int i=l+1;i<=r;i++){
        if(tmp-(a[l]-a[l-1])<=0){
            Min++;
            tmp=m;
        }
        else{
            tmp-=(a[l]-a[l-1]);
        }
    }
    ve[l].push_back({1,0});
    for(int i=l+1;i<=r;i++){
        tmp=m;
        for(int j=i;j>=l&&tmp>=0;j--){
            tmp-=(a[l]-a[l-1]);
            if(tmp<0){
                break;
            }
            for(auto t:ve[j]){
                if(t.ti<=Min&&t.zl<=2){
                    ve[i].push_back({t.zl,t.ti+1});
                }
            }
        }
    }
    int cnt=0;
    for(auto t:ve[r]){
        if(t.ti==Min){
            cnt++;
        }
    }
    if(cnt==2){
        return 1;
    }
    return 0;

}
int main(){
   // ios::sync_with_stdio(false);
   // cin.tie(0);
    //cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        //cout<<"%$^";
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(ch(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
