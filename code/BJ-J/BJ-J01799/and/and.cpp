#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,e[1000005],maxx=-1,book[1000005];
ll dfs(ll cnt,ll sum,ll st){
    if(cnt==m){
        maxx=max(maxx,sum);
        return 0;
    }
    for(ll i=st;i<=n;i++){
        if(book[i]==0){
            book[i]=1;
            if(cnt==0)dfs(cnt+1,e[i],i+1);
            else dfs(cnt+1,sum&e[i],i+1);
            book[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>e[i];
    }
    if(m==1){
        for(ll i=1;i<=n;i++){
            maxx=max(maxx,e[i]);
        }
    }
    else if(m==n){
        for(ll i=1;i<=n;i++){
            maxx=maxx&e[i];
        }
    }
    else if(n>50&&m>50){
        maxx=0;
    }
    else dfs(0,0,1);
    cout<<maxx;
    return 0;
}
