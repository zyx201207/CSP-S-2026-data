#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],dp[N],vis[N],cnt[N];
int pf1[N],tag[N];
void solve(int x){
    for(int i=1;i<=m;i++)vis[i]=0;
    for(int i=1;i<=n;i++)tag[i]=0;
    for(int i=1;i<=n;i++)pf1[i]=0;
    int tot=0;
    for(int i=x;i<=n;i++){
        if(!vis[a[i]]){pf1[++tot]=a[i];vis[a[i]]++;tag[a[i]]=tot;}
        else {
            for(int j=tag[i];j<=tot;j++){
                vis[pf1[j]]=0;tag[pf1[j]]=0;
            }
            tot=tag[i]-1;
            pf1[++tot]=a[i];vis[a[i]]=1;tag[a[i]]=tot;
        }
    }
    for(int i=1;i<=tot;i++)cnt[pf1[i]]++;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;int flg=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])flg=0;
    }
    if(flg==1){
        int cnt=0,tot=0;
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1])cout<<i-1<<" ";
        }
        cout<<n<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    for(int i=1;i<=n;i++)dp[i]=0;
    return 0;
}