#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],cnt[50010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        scanf("%lld",a+i);
        cnt[a[i]]++;
    }
    vector<ll>f;
    for(ll i=1;i<=n;i++){
        f.push_back(a[i]);
    }
    for(ll i=1;i<=m;i++){
        printf("%lld ",cnt[i]);
    }
    return 0;
}

