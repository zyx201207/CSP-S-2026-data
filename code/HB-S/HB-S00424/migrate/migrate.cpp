#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,a[2000005],d,ans,fl=1;
int t[2000005];
void dfs(int x,int tot,int v){
    if(x==v){
        t[tot]++;
        return;
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d)dfs(i,tot+1,v);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        ans=0;
        fl=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=3){
                if(a[i]-a[i-1]!=a[i-1]-a[i-2])fl=0;
            }
            }
            if(fl){
                int x=a[2]-a[1];
                if(d<2*x||d>3*x){
                    cout<<0<<'\n';
                    continue;
                }
                cout<<n-3<<'\n';
                continue;
            }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dfs(i,0,j);
                
                for(int k=1;k<=1e9;k++){
                    if(t[k]){
                        if(t[k]==2){
                            ans++;
                            //cout<<"ans"<<' '<<i<<' '<<j<<'\n';
                        }
                        break;
                    }
                }
                memset(t,0,sizeof(t));
            }
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}