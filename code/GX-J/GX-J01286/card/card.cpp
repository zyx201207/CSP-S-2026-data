#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll c[m+1] ;
    memset(c,0,sizeof(c));
    for(ll i=1;i<=n;i++){
        stack<ll> st;
        bool b[m+1];
        memset(b,false,sizeof(b));
        for(ll j=i;j<=n;j++){
            if(b[a[j]]){
                while(st.top() != a[j]){
                    st.pop();
                }
            }
            else{
                st.push(a[j]);
                b[a[j]] = true;
            }
        }
        while(! st.empty()){
            c[st.top()] ++;
            st.pop();
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
