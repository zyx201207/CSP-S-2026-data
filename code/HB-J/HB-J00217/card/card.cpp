#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    queue<ll>q;
    ans.resize(m + 1,0);
    for(ll i = 0;i < n;i++){
        ll temp;
        cin>>temp;
        q.push(temp);
    }
    for(ll i = 0;i < n;i++){
        if(i != 0){
           q.pop();
        }
        stack<ll>ta;
        vector<ll>ti;
        queue<ll>tq;
        tq = q;
        ti.resize(m + 1,0);
        while(!tq.empty()){
            ll t = tq.front();
            tq.pop();
            if(ti[t] == 1){
               while(ti[t] == 1){
                    ti[ta.top()] = 0;
                    ta.pop();
               }
            }
            ta.push(t);
            ti[t] = 1;
        }
        while(!ta.empty()){
            ans[ta.top()]++;
            ta.pop();
        }
    }
    for(ll i = 1;i <= m;i++)
    {
        cout<<ans[i];
        if(i != m){
            cout<<" ";
        }
    }
    return 0;
}
