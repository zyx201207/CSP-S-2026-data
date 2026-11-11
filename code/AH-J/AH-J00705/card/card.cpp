#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>zm,pd;
ll cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        pd.push_back(x);
    }
    for(int i=0;i<n;i++){
        zm.clear();
        for(int j=i;j<n;j++){
            zm.push_back(pd[j]);
            ll l=zm.size();
            for(int k=l-2;k>=0;k--){
                if(zm[k]==zm[l-1]){
                    for(int i=1;i<=l-1-k;i++)zm.pop_back();
                    break;
                }
            }
        }
        for(int i=0;i<zm.size();i++)cnt[zm[i]]++;
    }
    for(int i=1;i<=m;i++)printf("%lld ",cnt[i]);
    return 0;
}
