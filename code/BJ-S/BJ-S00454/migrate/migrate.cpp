#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int n,T,c,l[N],r[N],cnt[N];
long long d,a[N],ans,sz[N],rs[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            l[i]=r[i]=i;
        }
        c=1;
        for(int i=1;i<=n;i++)
            while(a[i]-a[c]>d)r[c++]=i-1;
        for(int i=c;i<=n;i++)r[i]=n;
        c=n;
        for(int i=n;i>0;i--)
            while(a[c]-a[i]>d)l[c--]=i+1;
        for(int i=1;i<=c;i++)l[i]=1;
        sz[1]=1;
        for(int i=2;i<=n;i++){
            if(l[i]==i-1&&r[i-1]==i)sz[i]=sz[i-1]+1;
            else sz[i]=1;
        }
        rs[n]=1;
        for(int i=n;i>0;i--){
            if(r[i]==i+1&&l[i+1]==i)rs[i]=rs[i+1]+1;
            else rs[i]=1;
        }
        for(int i=1;i<=n;i++){
            // cout<<l[i]<<' '<<r[i]<<'\n';
            if(l[i]+1!=i&&cnt[l[i]+1]){
                // cout<<cnt[l[i]+1]<<'\n';
                ans+=cnt[l[i]+1]*rs[i];
            }
            cnt[r[i]]+=sz[i];
        }
        for(int i=1;i<=n;i++)cnt[i]=0;
        cout<<ans<<'\n';
    }
    return 0;
}
//migrate