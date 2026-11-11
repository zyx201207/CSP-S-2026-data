#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll ar[500005];
ll pre[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    //cout<<n<<m;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    sort(ar+1,ar+1+n);
    for(int i=1;i<=n;i++)pre[i]=ar[i];
    for(int i=2;i<=n;i++){
        pre[i]=pre[i]+pre[i-1];
    }

    ll p1=0,p2=1;//p2:right,p1:left,get the (p1,p2]
    ll ans=0;
    while(p2<=n&&p1<=n){
        if(pre[p2]-pre[p1]+m>=1LL*ar[p2]*(p2-p1)){
            ans=max(ans,p2-p1);
            p2++;
        }else if(pre[p2]-pre[p1]+m<1LL*ar[p2]*(p2-p1)){
            p1++;
        }
    }
    cout<<ans;

}
