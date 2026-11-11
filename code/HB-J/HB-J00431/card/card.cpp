#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll>stk;
map<ll,ll>mp;
ll n,m,a[500005],t[300005];
int main(){
    freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        mp.clear();
        while(!stk.empty())stk.pop();
        for(int j=i;j<=n;j++){
            if(mp[a[j]]==0){
                mp[a[j]]++;
                stk.push(a[j]);
            }else{
                while(1){
                    ll p=stk.top();stk.pop();
                    mp[p]--;
                    if(p==a[j])break;

                }
                mp[a[j]]++;
                stk.push(a[j]);
            }
        }
        for(auto i:mp){
            if(i.second>0)t[i.first]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}

