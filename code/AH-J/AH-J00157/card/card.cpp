#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,m,a[N],cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    vector<LL> v1(n);
    for(LL i=1;i<=n;i++) cin>>v1[i];
    for(LL i=1;i<=n;i++){
        vector<LL> v(n);
        LL t=v.size();
        for(LL j=i+1;j<=n;j++){
            bool f=false;
            for(LL k=i+1;k<=min(n,t-1);k++)
                if(v[i]==a[i]){
                    f=true;
                    if(!v.empty()) v.erase(j,t-1);
                    v.insert(i,a[i]);
                    t++;
                    break;
                }
            if(!f){v.insert(i,a[i]);t++;}
        }
        for(LL i=0;i<t;i++) cnt[v[i]]++;
    }
    for(LL i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
