#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m,n,w[200000],ans=0;

void dfs(ll step,ll p,ll pos){
  //  cout << step <<' '<< p<<' '<< pos << ' '<<endl;
    if(step>=m){
       //     cout <<"check"<< p <<' '<< ans <<endl<< endl;
        ans=max(p,ans);

        return;
    }
    for(int i=pos+1;i<=n;i++){
        ll l=p&w[i];
      //  cout << p<<'&'<<w[i]<<'='<<l<<endl<<endl;
        dfs(step+1,l,i);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        w[i]=x;
    }
    for(ll i=1;i<=n;i++){
      //  cout << w[i];
        dfs(1,w[i],i);
    }
    cout << ans;
    return 0;
}
