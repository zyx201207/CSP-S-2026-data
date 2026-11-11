#include<bits/stdc++.h>
#define N 1000050
#define ll long long
#define qck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll a[N];
ll ans[N],nxt[N],pre[N];
int n,m;
stack<ll> stk;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    qck;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        nxt[i]=pre[a[i]];
        if(pre[a[i]]==0) pre[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            ans[a[j]]++;
            if(nxt[j]!=0) j=nxt[j],ans[a[j]]--;
            else j++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}