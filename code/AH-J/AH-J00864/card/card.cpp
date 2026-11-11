#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[1000100],t[1000100],ans[10000100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(ll ju=1;ju<=n;ju++){
        stack<ll> st;
        memset(t,0,sizeof t);
        for(ll i=ju;i<=n;i++){
            if(st.empty()){st.push(a[i]);t[a[i]]++;}
            else{

                if(t[a[i]]!=0){
                    while(!st.empty()){
                        ll x=st.top();
                        if(x==a[i])break;
                        st.pop();
                        t[x]--;
                    }

                }else{
                    st.push(a[i]);
                    t[a[i]]++;
                }

            }

        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
