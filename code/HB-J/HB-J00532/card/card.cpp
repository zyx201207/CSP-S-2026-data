#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int a[2000005],p[200005],ans[200005],sum[200005];
void get(int x){
    memset(p,0,sizeof p);
    for(int i=x;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            if(a[i]==p[j]){
                for(int k=j;k<=cnt;k++)p[k]=0;
                cnt=j;
                break;
            }
        }
        p[++cnt]=a[i];
    }
    for(int i=1;i<=cnt;i++){
        ans[p[i]]++;
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n>=500){
        for(int i=1;i<=n;i++)sum[a[i]]++;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(sum[i]==1)ans[i]++;
        //     }
        //     sum[a[i]]--;
        // }
        for(int i=1;i<=m;i++){
            sum[i]+=sum[i-1];
            cout<<sum[i]<<' ';
            }
        return 0;
    }
    for(int i=1;i<=n;i++){
        get(i);
        //for(int i=1;i<=cnt;i++)cout<<p[i]<<' ';
       // cout<<'\n';
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}