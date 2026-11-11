#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=3e5+5;
ll cnt[N],a[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++){
        ll f[N]{0};
        stack<ll>st;
        for(ll j=i;j<=n;j++){
            if(f[a[j]]!=0){
                while(st.top()!=a[j]){
                    f[st.top()]=0;
                    st.pop();
                }
            }else{
                st.push(a[j]);
                f[a[j]]=1;
            }
        }
        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
    }
    for(ll i=1;i<=m;i++){
        printf("%lld ",cnt[i]);
    }
    return 0;
}
