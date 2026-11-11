#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],b[N],c[N];
int n,m,tot,sum;
ll ans=0;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        c[++sum]=a[i];
    }
    for(int i=30;i>=0;i--){
        // int sum=0;
        tot=0;
        for(int j=1;j<=sum;j++){
            b[++tot]=c[j];
            // cout<<b[tot]<<"\n";
        }
        sum=0;
        for(int j=1;j<=tot;j++){
            // cout<<i<<"\n";
            if((b[j]>>(i))&1){
                c[++sum]=b[j];
                // cout<<i<<' '<<b[j]<<"\n";
            }
        }
        if(sum<m){
            for(int j=1;j<=tot;j++){
                // cout<<b[j]<<" ";
                c[j]=b[j];
            }
            sum=tot;
        }
        else{
            ans+=(1ll<<i);
            
        }
    }
    cout<<ans;
}