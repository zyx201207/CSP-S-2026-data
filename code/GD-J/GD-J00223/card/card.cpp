#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int M=3e5+10;
int a[N],n,m,nxt[N],pos[N],sum[N],ans[N],val[N];
bool vis[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(!pos[a[i]]){
            nxt[i]=n+1;
            pos[a[i]]=i;
        }
        else{
            nxt[i]=pos[a[i]];
        }
    }
    for(int i=1;i<=n;i++){
        val[i]++;
        if(nxt[i]==n+1){
            val[i+1]+=val[i];
        }
        else{
            val[nxt[i]+1]+=val[i];
        }
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=val[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}