#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,x[2000005],num[2000005],f[2000005],g[2000005],s[2000005],q[2000005],st,en;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c==11||c==12){
            int bl=d/(x[2]-x[1]);
            if(!bl||bl==1){
                cout<<"0"<<endl;
                continue;
            }
            cout<<max(0*1ll,n-2*bl+1)<<endl;
        }else if(c<=10){
            int ans=0;
            for(int i=1;i<=n;i++){
                f[i]=0;
                g[i]=1;
                s[i]=1;
                s[i-1]=0;
                for(int j=i+1;j<=n;j++){
                    int l=i,r=j,k;
                    while(l<r){
                        int mid=(l+r)>>1;
                        if(x[j]-x[mid]<=d)r=mid;
                        else l=mid+1;
                    }
                    if(l==j)break;
                    k=l;
                    r=j-1;
                    while(l<r){
                        int mid=(l+r+1)>>1;
                        if(f[mid]==f[k])l=mid;
                        else r=mid-1;
                    }
                    f[j]=f[k]+1;
                    g[j]=s[l]-s[k-1];
                    if(g[j]==2)ans++;
                    s[j]=s[j-1]+g[j];
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}