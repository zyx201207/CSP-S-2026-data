#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],g[500005],d[500005],f[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(b[a[i]]!=0){
            g[b[a[i]]]=i;
            f[i]=b[a[i]];
        }
        b[a[i]]=i;
    }
    int cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        if(g[i]!=0){
            d[i]-=i-sum;
            d[g[i]]+=i-sum;
            sum++;
        }
        if(f[i]!=0){
            sum--;
        }
        cnt+=d[i];
        ans[a[i]]=max(ans[a[i]],i+cnt);
        //cout<<d[i]<<' ';
    }
    //cout<<"\n";
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
