#include<bits/stdc++.h>
using namespace std;
#define int long long
int ccc,n,t;
int d;
int x[2000005];
int ftq[2000005];
int fth[2000005];
int f[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ccc>>t;
    while(t--){
        cin>>n>>d;
        int l=1;
        cin>>x[1];
        for(int i=2;i<=n;i++){
            cin>>x[i];
            while(x[i]-x[l]>d)
            l++;
            ftq[i]=l;
        }
        x[n+1]=x[n]+d+1;
        l=1;
        for(int i=1;i<=n;i++){
            while(x[l]-x[i]<=d)
            l++;
            fth[i]=l-1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int lans=ans;
            for(int j=1;j<i;j++){
                ans+=bool((fth[j]==ftq[i]+1)&&fth[j]<i)*(f[j]+1);
            }
            f[i]=ans-lans;
        }
        cout<<ans<<"\n";
    }
    return 0;
}